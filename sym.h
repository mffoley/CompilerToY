#include <stdio.h>

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
typedef struct symbol_struct symbol_struct;

struct symbol
{
  char *name;
  HashTable *hash_table;
  struct symbol *next;
  struct symbol *prev;
  int internal_scope;
  symbol *inner_scope;
};

struct symbol_struct
{
  char *name;
  HashTable *hash_table;
  struct symbol_struct *next;
  struct symbol_struct *prev;
};

symbol *sym_table = NULL;
symbol_struct *struct_table = NULL;
symbol *current = NULL; // current scope
symbol_struct *head_struct = NULL;
Node *node_list_head = NULL;
void *create_symbol_table();
HashTable *create_hash_table();
int delete_scope();
unsigned long hash_function(char *varible);

void *delete_node_list()
{
  node_list_head = NULL;
  printf("NODE LIST DELETED\n");
}

void *print_node_list()
{

  Node *node;
  node = node_list_head;
  int i = 0;
  while (node != NULL)
  {
    printf("%d\n", i);
    printf("ID : %s\n", node->var_nam);
    printf("TYPE : %d\n", node->type);
    node = node->next;
    i++;
  }
}

void *print_struct_table()
{
  symbol_struct *sym = head_struct;
  while (sym != NULL)
  {
    printf("STRUCT NAME : %s\n", sym->name);

    HashTable *table = sym->hash_table;
    for (int i = 0; i < table->size; i++)
    {
      if (table->items[i] != NULL)
      {
        printf("VAR NAME : %s\n", table->items[i]->var);
      }
    }

    sym = sym->next;
  }
}

void *print_symbol_table()
{
  symbol *sym = current;
  while (sym != NULL)
  {
    printf("PROC NAME : %s\n", sym->name);

    HashTable *table = sym->hash_table;
    for (int i = 0; i < table->size; i++)
    {
      if (table->items[i] != NULL)
      {
        printf("VAR NAME : %s\n", table->items[i]->var);
      }
    }

    sym = sym->next;
  }
}

int add_to_node_list(int type, char *v)
{

  char *token = (char *)malloc(sizeof(char));
  strcpy(token, v);
  char *name_var = strtok(token, ";");

  Node *node = (Node *)malloc(sizeof(Node));

  node->type = type;
  node->var_nam = name_var;

  if (node_list_head == NULL)
  {
    node_list_head = node;
  }

  else
  {
    Node *curr = node_list_head;
    while (1)
    {
      if (curr->next == NULL)
      {
        curr->next = node;
        break;
      }
      curr = curr->next;
    };
  }
  return 0;
}

void *create_symbol_table()
{
  sym_table = (symbol *)malloc(sizeof(symbol));
  sym_table->next = NULL;
  sym_table->prev = NULL;
  sym_table->hash_table = NULL;
  sym_table->name = NULL;
  sym_table->internal_scope = 0;
  sym_table->inner_scope = NULL;
  current = sym_table;

  printf("TABLE CREATED\n");
}

void *create_struct_table()
{
  struct_table = (symbol_struct *)malloc(sizeof(symbol_struct));
  struct_table->next = NULL;
  struct_table->prev = NULL;
  struct_table->hash_table = NULL;
  struct_table->name = NULL;

  head_struct = struct_table;
  printf("STRUCT TABLE CREATED\n");
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

add_internal_scope()
{
  current->inner_scope = (symbol *)malloc(sizeof(symbol));
  current->inner_scope->prev = current;
  current = current->inner_scope;
  current->next = NULL;
  current->internal_scope = 1;
  current->hash_table = (HashTable *)malloc(sizeof(HashTable));

  Node *node;
  for (node = node_list_head; node != NULL; node = node->next)
    {
      if (check_scope(node->var_nam) == 0)
      {
        int index = hash_function(node->var_nam);
        items *n = (items *)malloc(sizeof(items));
        n->return_type = NULL;
        n->type = node->type;
        n->var = node->var_nam;
        current->hash_table->items[index] = n;
      }
      else
      {
        //Var already declared
        return 0; 
      }
    }
}

HashTable *create_hash_table_struct()
{
  HashTable *table = (HashTable *)malloc(sizeof(HashTable));
  table->size = SIZE;
  table->count = 0;
  table->items = (items **)calloc(table->size, sizeof(items *));
  for (int i = 0; i < table->size; i++)
    table->items[i] = NULL;

  printf("STRUCT HASH TABLE CREATED\n");
  return table;
}

void *add_to_struct_table(char *struct_name)
{
  char *name = (char *)malloc(sizeof(char));
  strcpy(name, struct_name);
  char *token = strtok(name, "{");

  if (check_struct_name(token) == 0)
  {
    symbol_struct *pre = NULL;
    if (head_struct == NULL)
      create_struct_table();
    else
    {
      while (head_struct != NULL)
      {
        pre = head_struct;
        head_struct = head_struct->next;
      }
    }

    head_struct = (symbol_struct *)malloc(sizeof(symbol_struct));
    head_struct->name = token;
    head_struct->next = NULL;
    head_struct->prev = pre;
    head_struct->hash_table = create_hash_table_struct();

    if (pre != NULL){
      pre->next = head_struct;
    }

    Node *node;

    for (node = node_list_head; node != NULL; node = node->next)
    {
      if (check_scope_struct(node->var_nam) == 0)
      {
        int index = hash_function(node->var_nam);
        items *n = (items *)malloc(sizeof(items));
        n->return_type = NULL;
        n->type = node->type;
        n->var = node->var_nam;
        head_struct->hash_table->items[index] = n;
        printf("ADDING: %s\n", n->var);
      }
      else
      {
        return 0;
      }
    }

    while (head_struct->prev != NULL)
      head_struct = head_struct->prev;

  }
  else
  {
    return 0;
  }
}

int check_struct_name(char *name)
{
  symbol_struct *curr = head_struct;
  char *n = strtok(name, " ");
  printf("%s\n", n);
  while (curr != NULL)
  {
    if (strcmp(curr->name, n) == 0)
    {
      printf("Struct already declared\n");
      return 1;
    }
    curr = curr->next;
  }
  if (head_struct != NULL)
  {
    while (head_struct->prev != NULL)
      head_struct = head_struct->prev;
  }
  return 0;
}

add_struct_to_scope(char* n)
{
  symbol_struct *curr = head_struct;
  char *name = strtok(n, " ");
  printf("%s\n", name);

  HashTable *table = head_struct->hash_table;
  if (table != NULL)
  {
    for(int index = 0; index < table->size; index ++)
    {
      items *item = table->items[index];
      if(item != NULL)
      {
        add_to_node_list(item->type, item->var);
      }
    }

  }


}

int check_scope_struct(char *n)
{
  int index = hash_function(n);
  while (head_struct->next != NULL)
    head_struct = head_struct->next;
  HashTable *table = head_struct->hash_table;
  if (table != NULL)
  {
    items *item = table->items[index];
    if (item != NULL)
    {
      return 1;
    }
  }
   //Variable not in scope
  return 0;
}


void *add_to_symbol_table(char *proc_name)
{
  print_node_list();
  char *token = (char *)malloc(sizeof(char));
  strcpy(token, proc_name);

  char *name = strtok(token, "(");
  if (check_proc_name(name) == 0)
  {
    symbol* pre = NULL;
    if (current == NULL)
    {
      create_symbol_table();
    }
    else {
      while(current != NULL)
      {
        pre = current;
        current = current->next;
      }
    }
    
    current = (symbol *)malloc(sizeof(symbol));
    current->name = name;
    current->next = NULL;
    current->prev = pre;

    current->hash_table = create_hash_table();

    if (pre != NULL)
       pre->next = current;

    Node *node;
    for (node = node_list_head; node != NULL; node = node->next)
    {
      if (check_scope(node->var_nam) == 0)
      {
        int index = hash_function(node->var_nam);
        items *n = (items *)malloc(sizeof(items));
        n->return_type = NULL;
        n->type = node->type;
        n->var = node->var_nam;
        current->hash_table->items[index] = n;
      }
      else
      {
        //Var already declared
        return 0; 
      }
    }
   
    while (current->prev != NULL)
      current = current->prev;
    
    return 1; 
  }
  else return 0;
}

int check_proc_name(char *name)
{
  symbol *sym = current;
  while (sym != NULL)
  {
    if (strcmp(sym->name, name) == 0)
    {
      return 1;
      printf("PROC EXISTS\n");
    }
    sym = sym->next;
  }
  if (current != NULL)
  {
    while (current->prev != NULL)
      current = current->prev;
  }
  return 0;
}

int delete_scope()
{
  current->hash_table = NULL;
  current->prev->next = NULL;
  current = current->prev;
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
  HashTable *table = current->hash_table;
  if (table != NULL)
  {
    items *item = (items *)malloc(sizeof(items));
    item = table->items[index];
    if (item != NULL)
    {
      //if (strcmp(item->var, n) == 0)
        return 1;
    }
  }
  //Variable not in scope
  return 0;
}

int check_struct_in_scope(char* s)
{
  char *token = (char *)malloc(sizeof(char));
  strcpy(token, s);
  char *n = strtok(token, ".");

  int index = hash_function(n);
  HashTable *table = current->hash_table;
  if (table != NULL)
  {
    items *item = (items *)malloc(sizeof(items));
    item = table->items[index];
    printf("%s", item->var);
    if (item != NULL)
    {
      if (strcmp(item->var, n) == 0){
        if(item->type == 7){
          printf("Scoop\n");
        return 1;
        }
      }
    }
  }
  //Variable not in scope
  return 0;
}
