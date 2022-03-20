#include <stdio.h>

struct symbol
{
  char *name;
  struct symbol *next;
};

typedef struct symbol symbol;
symbol *sym_table = NULL;
symbol *put();
symbol *get();

symbol* put(char *name)
{
  symbol *ptr = (symbol*) malloc(sizeof(symbol));
  ptr->name = (char*) malloc(strlen(name));
  ptr->name = name;
  ptr->next = (struct symbol *)sym_table;
  sym_table = ptr;
  return ptr;
}

symbol* get(char *name)
{
  symbol *ptr;
  for (ptr = sym_table; ptr != NULL;  ptr = (symbol *)ptr->next)
  {
    if (strcmp (ptr->name, name) == 0)
    return ptr;
  }
  return 0;
}
