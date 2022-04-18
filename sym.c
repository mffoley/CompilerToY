#include <stdio.h>
#include <string.h>


#define SIZE 256;

#define VARIABLES 1;
#define PROC 2;
#define STRUCT_STMT 3;

table *symbol_table = NULL;
symbol *current = NULL; // current scope
char *struct_name;

int add_to_scope(int type, char *n)
{
  char *name = (char *)malloc(sizeof(char));
  strcpy(name, n);
  char *var_name = strtok(name, ";");

  int scope = check_scope(var_name);

  if (symbol_table == NULL)
  {
    create_symbol_table();
  }

  if (scope == 0)
  {
    int index = hash_function(var_name);
    items *n = (items *)malloc(sizeof(items));
    n->type = (int)malloc(sizeof(int));
    symbol_table->curr->hash_table->items[index] = n;
    n->return_type = NULL;
    n->type = type;
    n->var = var_name;
    n->field_of = NULL;
    n->name_struct = NULL;
    return 1;
  }
  else
  {
    return 0;
  }
}

int is_struct(int integer)
{
  if (integer == 1)
    symbol_table->curr->is_struct = 1;
  else
    symbol_table->curr->is_struct = 0;
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
  symbol *new = (symbol *)malloc(sizeof(symbol));
  new->hash_table = create_hash_table();
  new->inner_scope = NULL;
  new->internal_scope = 0;
  new->name = NULL;
  new->next = NULL;
  new->prev = symbol_table->curr;
  new->is_struct = 0;
  symbol_table->curr->next = new;
  symbol_table->curr = symbol_table->curr->next;
}

void *print_symbol_table()
{
  symbol *sym = symbol_table->head;
  while (sym != NULL)
  {
    printf("NAME : %s\n", sym->name);
    if (sym->is_struct == 1)
      printf("Struct\n");
    if (sym->return_type != NULL)
      printf("Return Type %d\n", sym->return_type);

    HashTable *table = sym->hash_table;
    for (int i = 0; i < table->size; i++)
    {
      if (table->items[i] != NULL)
      {
        printf("VAR NAME : %s, VAR TYPE : %d", table->items[i]->var, table->items[i]->type);
        if (table->items[i]->name_struct != NULL)
        {
          printf(" STRUCT NAME : %s", table->items[i]->name_struct);
        }
        if (table->items[i]->field_of != NULL)
        {
          printf(" FIELD OF : %s", table->items[i]->field_of);
        }
        printf("\n");
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
          printf("VAR NAME : %s, VAR TYPE : %d\n", table->items[i]->var, table->items[i]->type);
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
  first->return_type = NULL;
  first->hash_table = create_hash_table();
  symbol_table->curr = first;
  symbol_table->head = first;
  symbol_table->curr->is_struct = 0;
}

HashTable* create_hash_table()
{
  HashTable *table = (HashTable *)malloc(sizeof(HashTable));
  table->size = SIZE;
  table->count = 0;
  table->items = (items **)calloc(table->size, sizeof(items *));
  for (int i = 0; i < table->size; i++)
    table->items[i] = NULL;

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
  symbol_table->curr->is_struct = 0;
}

void delete_scope()
{
  if (symbol_table->curr->prev != NULL)
  {
    symbol_table->curr = symbol_table->curr->prev;
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
          return 1;
        }
      }
      temp = temp->prev;
    }
  }
  // checking outer scope
  table = temp->hash_table;
  if (table != NULL)
  {
    items *item = (items *)malloc(sizeof(items));
    item = table->items[index];
    if (item != NULL)
    {
      return 1;
    }
  }
  return 0;
}

int add_struct_to_scope(char *field)
{
  symbol *temp = symbol_table->head;

  while (temp != NULL)
  {
    if ((temp->is_struct == 1))
    {
      if (temp->name != NULL && struct_name != NULL)
      {
        if (strcmp(struct_name, temp->name) == 0)
        {
          HashTable *table = temp->hash_table;
          if (table != NULL)
          {
            for (int index = 0; index < table->size; index++)
            {
              items *item = table->items[index];
              if (item != NULL)
              {
                if (add_to_scope(item->type, item->var) == 1)
                {
                  if (item->field_of != NULL)
                  {
                  }
                  add_struct(item->var);
                }
              }
            }
          }
          return 1;
        }
      }
    }
    temp = temp->next;
  }
  return 0;
}

int check_if_struct(char *name)
{
  symbol *temp = symbol_table->curr;

  HashTable *table = temp->hash_table;
  if (table != NULL)
  {
    items *item = (items *)malloc(sizeof(items));
    for (int index = 0; index < table->size; index++)
    {
      item = table->items[index];
      if (item != NULL)
      {
        if (strcmp(name, item->var) == 0 && item->type == 7)
          return 1;
      }
    }
  }
  temp = temp->next;
  return 0;
}

void store_struct_name(char *name)
{
  struct_name = (char *)malloc(sizeof(char));
  strcpy(struct_name, name);
}

// make sure name_struct is null
void add_struct_name()
{
  symbol *temp = (symbol *)malloc(sizeof(symbol));
  temp = symbol_table->curr;
  HashTable *table = temp->hash_table;
  if (table != NULL)
  {
    items *item = (items *)malloc(sizeof(items));
    for (int index = 0; index < table->size; index++)
    {
      item = table->items[index];
      if (item != NULL)
      {
        if (item->type == 7 && item->name_struct == NULL)
        {
          char *c = (char *)malloc(sizeof(char));
          strcpy(c, struct_name);
          item->name_struct = c;
          break;
        }
      }
    }
  }
}

ExpType* return_type(char *var)
{
  int index = hash_function(var);
  ExpType* rettype = (ExpType *)malloc(sizeof(ExpType));
  symbol *temp = symbol_table->curr;
  HashTable *table = temp->hash_table;
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
          printf("\nfound the rettype: %d\n", item->type);
          if (item->type==7){
            rettype->sname = item->name_struct;
          }
          rettype->type = item->type;
          return rettype;
        }
      }
      temp = temp->prev;
    }
  }
  // checking outer scope
  table = temp->hash_table;
  if (table != NULL)
  {
    items *item = (items *)malloc(sizeof(items));
    item = table->items[index];
    if (item != NULL)
    {
      printf("\nfound the rettype: %d\n", item->type);
      if (item->type==7){
            rettype->sname = item->name_struct;
          }
          rettype->type = item->type;
          return rettype;
    }
  }
  return 0;
}

int check_if_field(char *stmt)
{
  char *token1 = strtok(stmt, ".");
  char *token2 = strtok(NULL, ".");

  if (check_scope(token1) != 0 && check_scope(token2) != 0)
  {
    symbol *temp = symbol_table->curr;
    HashTable *table = temp->hash_table;
    int index = hash_function(token1);

    if (table != NULL)
    {
      items *item = (items *)malloc(sizeof(items));
      item = table->items[index];

      if (item->name_struct != NULL)
      {
        char *name_of_struct = item->name_struct;
        temp = symbol_table->head;
        while (temp != NULL)
        {
          if ((strcmp(temp->name, name_of_struct) == 0) && temp->is_struct == 1 && item->type == 7)
          {
            table = temp->hash_table;

            index = hash_function(token2);
            items *item2 = (items *)malloc(sizeof(items));
            item2 = table->items[index];
            if (item2 != NULL)
            {
              if (item2->type == 7)
              {
                return 1;
              }
              index = hash_function(token1);
              items *item1 = (items *)malloc(sizeof(items));
              item1 = table->items[index];
              if (item1 != NULL && item2 != NULL)
              {
                if (strcmp(item1->name_struct, item2->name_struct) == 0)
                {
                  return 1;
                }
                else
                  return 0;
              }
            }
            else
              return 0;
          }
          temp = temp->next;
        }
        return 0;
      }
      else
        return 0;
    }
    else
      return 0;
  }
}

add_struct(char *name)
{
  symbol *temp = (symbol *)malloc(sizeof(symbol));
  temp = symbol_table->curr;
  HashTable *table = temp->hash_table;
  if (table != NULL)
  {
    items *item = (items *)malloc(sizeof(items));
    int index = hash_function(name);
    item = table->items[index];
    if (item != NULL)
    {

      if (strcmp(item->var, name) == 0)
      {
        char *c = (char *)malloc(sizeof(char));
        strcpy(c, struct_name);
        item->name_struct = (char *)malloc(sizeof(char));
        strcpy(item->name_struct, c);
      }
    }
  }
}

void store_return_type(int type)
{
  if (symbol_table == NULL)
  {
    create_symbol_table();
  }
  symbol_table->curr->return_type = type;
}

ExpType* get_return_type_current_proc()
{
  printf("trying to get curr rettype\n");
  ExpType* rettype = (ExpType *)malloc(sizeof(ExpType));

  rettype->type = symbol_table->curr->return_type;
  rettype->sname = symbol_table->curr->name;
  printf ("the expression type of the current proc is %d , %s \n",rettype->type,rettype->sname);
  return rettype;
}

int get_return_type_of_a_proc(char *name)
{
  symbol *sym = symbol_table->head;
  while (sym != NULL)
  {
    if ((strcmp(sym->name, name) == 0) && sym->is_struct == 0)
    {
      printf("\n\nreturn type is %d\n",sym->return_type);
      return sym->return_type;
    }
    sym = sym->next;
  }
  printf("\ndid not find the proc\n");
  return -1;
}