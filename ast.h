#include <stdio.h>
#include <string.h>


typedef struct Expression {
  int evaluates_to_type;
  int op;
  int exp_type;
  struct Expression *lexp;
  struct Expression *rexp;
} Expression;


//Use check_scope sym table for types

// For variables and types, just put their type into evaluates to... and use nexp

// Are there any operations that can evaluate to multiple types?  - can use the op type

// Function to check expected type vs the actual return type

// For return, check the symbol table for the current func

// Assignment not handled in here

Expression* add_expression (int type, int op, int exp, Expression *lexp, Expression *rexp);
void print (Expression *node);
void printtree (int indent, Expression *exp);
int verify (Expression *node);

int check_compatibility ( int type_expected, Expression *root );
