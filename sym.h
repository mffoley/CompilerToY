#include <stdio.h>
#include <string.h>

#define SIZE 256;

#define VARIABLES 1;
#define PROC 2;
#define STRUCT_STMT 3;

#define INT_TYPE 4;
#define BOOL_TYPE 5;
#define STRING_TYPE 6;
#define VAR_STRUCT 7;
#define FIELD_STRUCT 8;

typedef struct HashTable HashTable;
typedef struct items items;
typedef struct Node Node;

struct items
{
  char *var;
  HashTable *value;
  int return_type;
  int type;
};

struct Node
{
  char *var_nam;
  int type;
  struct Node *next;
};

struct HashTable
{
  items **items;
  int size;
  int count;
};

typedef struct symbol symbol;
typedef struct table table;

struct symbol
{
  char *name;
  HashTable *hash_table;
  struct symbol *next;
  struct symbol *prev;
  int internal_scope;
  symbol *inner_scope;
};

struct table
{
  symbol *head;
  symbol *curr;
};

table *symbol_table = NULL;
symbol *current = NULL; // current scope
symbol *previous = NULL;
Node *node_list_head = NULL;
void *create_symbol_table();
HashTable *create_hash_table();
unsigned long hash_function(char *varible);

int add_to_scope(int type, char *n)
{
  char *name = (char *)malloc(sizeof(char));
  strcpy(name, n);
  char *var_name = strtok(name, ";");

  if (symbol_table == NULL)
  {
    create_symbol_table();
  }

  if (check_scope(var_name) == 0)
  {
    int index = hash_function(var_name);
    items *n = (items *)malloc(sizeof(items));
    n->return_type = NULL;
    n->type = type;
    n->var = var_name;
    symbol_table->curr->hash_table->items[index] = n;
    printf("ADDING: %s\n", n->var);
    return 1;
  }
  else
  {
    printf("Here with: %s\n", var_name);
    return 0;
  }
}

int add_name(char *name)
{
  if (symbol_table == NULL)
  {
    create_symbol_table();
  }
  if (check_name(name) == 1)
  {
    char *token = (char *)malloc(sizeof(char));
    strcpy(token, name);
    symbol_table->curr->name = token;
    return 1;
  }
  else
    return 0;
}

int check_name(char *name)
{
  symbol *sym = symbol_table->head;
  while (sym != NULL && sym->name != NULL)
  {
    if (strcmp(name, sym->name) == 0)
      return 0;
    else
    {
      sym = sym->next;
    }
  }
  return 1;
}

void new_scope()
{
  printf("New Scope\n");
  symbol *new = (symbol *)malloc(sizeof(symbol));
  new->hash_table = create_hash_table();
  new->inner_scope = NULL;
  new->internal_scope = 0;
  new->name = NULL;
  new->next = NULL;
  new->prev = symbol_table->curr;
  symbol_table->curr->next = new;
  symbol_table->curr = symbol_table->curr->next;
}

void *print_symbol_table()
{
  symbol *sym = symbol_table->head;
  while (sym != NULL)
  {
    printf("NAME : %s\n", sym->name);

    HashTable *table = sym->hash_table;
    for (int i = 0; i < table->size; i++)
    {
      if (table->items[i] != NULL)
      {
        printf("VAR NAME : %s\n", table->items[i]->var);
      }
    }

    while (sym->inner_scope != NULL)
    {
      printf("Inner Scope\n");

      HashTable *table = sym->inner_scope->hash_table;
      for (int i = 0; i < table->size; i++)
      {
        if (table->items[i] != NULL)
        {
          printf("VAR NAME : %s\n", table->items[i]->var);
        }
      }
      sym = sym->inner_scope;
    }

    while (sym->internal_scope != 0)
    {
      sym = sym->prev;
    }

    sym = sym->next;
  }
}

void *create_symbol_table()
{
  symbol_table = (table *)malloc(sizeof(table));
  symbol *first = (symbol *)malloc(sizeof(symbol));
  first->inner_scope = NULL;
  first->internal_scope = 0;
  first->name = NULL;
  first->next = NULL;
  first->prev = NULL;
  first->hash_table = create_hash_table();
  symbol_table->curr = first;
  symbol_table->head = first;
  printf("TABLE CREATED\n");
}

HashTable *create_hash_table()
{
  HashTable *table = (HashTable *)malloc(sizeof(HashTable));
  table->size = SIZE;
  table->count = 0;
  table->items = (items **)calloc(table->size, sizeof(items *));
  for (int i = 0; i < table->size; i++)
    table->items[i] = NULL;

  printf("HASH TABLE CREATED\n");
  return table;
}

void add_internal_scope()
{

  symbol_table->curr->inner_scope = (symbol *)malloc(sizeof(symbol));
  symbol_table->curr->inner_scope->prev = symbol_table->curr;
  symbol_table->curr->inner_scope->next = NULL;
  symbol_table->curr->inner_scope->hash_table = create_hash_table();
  symbol_table->curr = symbol_table->curr->inner_scope;
  symbol_table->curr->internal_scope = 1;
  printf("Added Internal Scope\n");
}

void delete_scope()
{
  if (symbol_table->curr->prev != NULL)
  {
    symbol_table->curr = symbol_table->curr->prev;
    printf("deleted!\n");
  }
}

unsigned long hash_function(char *variable)
{
  unsigned long i = 0;
  for (int j = 0; variable[j]; j++)
    i += variable[j];
  return i % SIZE;
}

int check_scope(char *name)
{
  char *token = (char *)malloc(sizeof(char));
  strcpy(token, name);
  char *n = strtok(token, " =");

  int index = hash_function(n);
  symbol *temp = symbol_table->curr;
  HashTable *table = temp->hash_table;
  printf("hey hey\n");
  if (temp->internal_scope == 1)
  {
    while (temp->internal_scope != 0)
    {
      HashTable *table = temp->hash_table;
      if (table != NULL)
      {
        items *item = (items *)malloc(sizeof(items));
        item = table->items[index];
        if (item != NULL)
        {
          printf("Variable in some internal scope: %s", temp->name);
          // if (strcmp(item->var, n) == 0)
          return 1;
        }
      }
      temp = temp->prev;
    }
  }
  //checking outer scope
    table = temp->hash_table;
      if (table != NULL)
      {
        items *item = (items *)malloc(sizeof(items));
        item = table->items[index];
        if (item != NULL)
        {
          printf("Variable in outer scope: %s\n", name);
          // if (strcmp(item->var, n) == 0)
          return 1;
        }
      }
  printf("Variable not in scope\n");
  return 0;
}