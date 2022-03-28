#include <stdio.h>

#define SIZE 256;

#define VARIABLES 1;
#define PROC 2;
#define STRUCT_STMT 3;

#define INT_TYPE 4;
#define BOOL_TYPE 5;
#define STRING_TYPE 6;
#define VAR_STRUCT 7;

typedef struct HashTable HashTable;
typedef struct items items;

struct items {
    char* var;
    HashTable* value;
    int return_type;
    int type;
};

struct HashTable {
    items** items;
    int size;
    int count;
};

typedef struct symbol symbol;

struct symbol
{
  HashTable *hash_table;
  struct symbol *next;
  struct symbol *prev;
};

symbol *sym_table = NULL;
symbol *current = NULL;
void* create_symbol_table();
void* create_hash_table();
int delete_scope();
unsigned long hash_function(char* var);


void* create_symbol_table()
{ 
  sym_table = (symbol*) malloc (sizeof(symbol));
  sym_table->next = NULL;
  sym_table->prev = NULL;
  sym_table->hash_table = NULL;
  current = sym_table;
  printf("TABLE CREATED\n");

}

void* create_hash_table(){
    HashTable* table = (HashTable*) malloc (sizeof(HashTable));
    table->size = SIZE;
    table->count = 0;
    table->items = (items**) calloc (table->size, sizeof(items*));
    for (int i=0; i<table->size; i++)
        table->items[i] = NULL;

    if(current->hash_table == NULL)
    {
      current->hash_table = table;
    }
    else{
      current->next = (symbol*) malloc (sizeof(symbol));
      current->next->prev = current;
      current->next->hash_table = table;
      current = current->next;
    }
      sym_table->hash_table = table;
      printf("HASH TABLE CREATED\n");
}

void* add_to_scope(char* name, int type) 
{
    if (sym_table == NULL) create_symbol_table();
    if(current->hash_table == NULL){
      create_hash_table();
    }
    insert(name, type);
}

void* new_scope() 
{
  if(sym_table != NULL){
  sym_table->next = (symbol*) malloc (sizeof(symbol));
  sym_table->prev = sym_table;
  current = sym_table->next;
  create_hash_table();
  }
  else{
    create_symbol_table();
  }

}

//delete scope
int delete_scope()
{
  current->hash_table = NULL;
  current->prev->next = NULL;
  current = current->prev;
}

unsigned long hash_function(char* var) {
    unsigned long i = 0;
    for (int j=0; var[j]; j++)
        i += var[j];
    return i % SIZE;
}

void insert(char* var, int type)
{
  if(check_scope(var) == 0){
    int index = hash_function(var); 
    items *node = (items*) malloc (sizeof(items));
    node->return_type = NULL;
    node->type = type;
    node->var = var;
    current->hash_table->items[index] = node;
  }
  else{
    printf("Variable already declared\n");
  }
}

 int check_scope (char *name)
  { 
    int index = hash_function(name);
    HashTable* table = current->hash_table;
    if(table != NULL) {
    items* item = table->items[index];
      if (item != NULL) {
              return 1;
      }
    }
    return 0;
}
