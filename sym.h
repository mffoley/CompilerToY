#include <stdio.h>
#include <string.h>

#define SIZE 256;

#define VARIABLES 1;
#define PROC 2;
#define STRUCT_STMT 3;

typedef struct items
{
  char *var;
  int return_type;
  int type;
  char *name_struct;
  char *field_of;
}items;

typedef struct HashTable
{
  items **items;
  int size;
  int count;
}HashTable;

typedef struct symbol
{
  char *name;
  HashTable *hash_table;
  struct symbol *next;
  struct symbol *prev;
  int internal_scope;
  int is_struct;
  struct symbol *inner_scope;
  int return_type;
}symbol;

typedef struct table
{
  symbol *head;
  symbol *curr;
}table;


int add_to_scope(int type, char *n);

int is_struct(int integer);

int check_name(char *name);

void new_scope();

void *print_symbol_table();

void *create_symbol_table();

HashTable* create_hash_table();

void add_internal_scope();

void delete_scope();

unsigned long hash_function(char *variable);

int check_scope(char *name);

int add_struct_to_scope(char *field);

int check_if_struct(char *name);

void store_struct_name(char *name);

void add_struct_name();

ExpType* return_type(char *var);

int check_if_field(char *stmt);

add_struct(char *name);

void store_return_type(int type);

ExpType* get_return_type_current_proc();

int get_return_type_of_a_proc(char *name);

int check_for_main();