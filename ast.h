#include <stdio.h>
#include <string.h>

#define INT_TYPE 4;
#define BOOL_TYPE 5;
#define STRING_TYPE 6;
#define VAR_STRUCT 7;
#define FIELD_STRUCT 8;

#define COMP_OP_R 9;  // Comparison Operator (Restrictive)
#define COMP_OP_NR 10;  // Comparison Operator (Not Restrictive)
#define M_OP 11;    // Maths operator

#define BEXP 12;  // Binary Operator
#define UEXP 13;  // Unary operator
#define NEXP 14;  // Not an Operator


//Use check_scope sym table for types

struct Variable {
  char* name;
  //Use the symbol table when type checking
}

struct Literal {
  int type;
}

// For variables and types, just put their type into evaluates to... and use nexp

// Are there any operations that can evaluate to multiple types?  - can use the operator type

// Function to check expected type vs the actual return type

// For return, check the symbol table for the current func

// Assignment not handled in here

struct Expression {
  int evaluates_to_type;
  int operator;
  int exp_type;
  struct Expression *lexp;
  struct Expression *rexp;
  struct Expression *parentexp;
}

Expression *tree_root = NULL;
Expression *current_expression = NULL;
void *add_expression();

Expression *add_expression (int type, int op, int exp, Expression lexp, Expression rexp) {
  struct Expression next_expression = (Expression *)malloc(sizeof(Expression));
  next_expression->evaluates_to_type = type;
  next_expression->exp_type = exp;
  next_expression->operator = op;


  if (tree_root == NULL)
  {
    tree_root = next_expression;
    current_expression = next_expression;
  }
  else
  { 
    // Place the new expression

    int placed = 0;
    next_expression->parentexp = current_expression;
    if (current_expression->operator == BEXP){
      if (current_expression->lexp == NULL){
        current_expression->lexp = *next_expression;
        placed = 1;
      }
      else if (current_expression->rexp == NULL){
        current_expression->rexp = *next_expression;
        placed = 1; 
      }
    }
    else if (current_expression->operator == UEXP){
      if (current_expression->rexp == NULL){
        current_expression->rexp = *next_expression;
        placed = 1; 
      }
    }
    if (placed != 1){
      printf("Could not place new exp");
    }

    next_expression->parentexp = current_expression;

    // Get the location for the next expression
    // Do not need to traverse downwards as long as all of the lefts are built before any rights
    if ( exp == NEXP ) {
      Expression node_find = current_expression;
      int found = 0;
      while (found != 1 && node_find!=NULL){
        if (node_find==UEXP){
          if (node_find->rexp == NULL){
            //this parent is not full 
            found = 1;
          }
        }
        else if (node_find == BEXP){
          if (node_find->rexp == NULL||node_find->lexp == NULL){
            //this parent is not full 
            found = 1;
          }
        }
        if (found != 1){
          node_find = node_find->parentexp;
        }
      }
      if (found==0){
        printf("cannot determine where next exp will be placed.");
      }
    }
    else if ( exp == UEXP || exp == BEXP) {
      current_expression = *next_expression;

    }

  }
}

void print () {
  printtree ("",tree_root);
}

void printtree (int indent, struct Expression exp) {
  //traverse down
  if (exp != NULL){
    for (int i = 0; i < indent; i++)
        printf("/t");
    if (exp->exp_type == BEXP){
      printf("Binary Expression");
    }
    else if (exp->exp_type == UEXP){
      printf("Unary Expression");
    }
    else if (exp->exp_type == NEXP){
      if (exp->evaluates_to_type == INT_TYPE){
        printf("Int");
      }
      if (exp->evaluates_to_type == BOOL_TYPE){
        printf("Bool");
      }
      if (exp->evaluates_to_type == STRING_TYPE){
        printf("String");
      }
    }
  }
  printtree(indent+1,exp->lexp);
  printtree(indent+1,exp->rexp);
}

// Pass in null to start, returns the return type of the thing below it
int *verify (Expression node) {
  // Do all verification steps - work to bottom of all expressions until two literals, work back up 
  if (node == NULL){
    node = tree_root;
  }
  int left_verif;
  int right_verif;
  left_verif = -1;
  right_verif = -1;

  if (node->rexp != NULL && node->rexp->exp_type == NEXP){
    right_verif = node->rexp->evaluates_to_type;
  }
  else if (node->rexp != NULL && (node->rexp->exp_type == UEXP || node->rexp->exp_type == BEXP)){
    right_verif = verify(node->rexp);
  }

  if (node->lexp != NULL && node->lexp->exp_type == NEXP){
    left_verif = node->lexp->evaluates_to_type;
  }
  else if (node->lexp != NULL && (node->lexp->exp_type == UEXP || node->lexp->exp_type == BEXP)){
    left_verif = verify(node->lexp);
  }

  if (node->exp_type == BEXP) {
    if (left_verif != -1 && right_verif != -1){
      if (node->operator == M_OP)
      {
        if (left_verif == INT_TYPE && right_verif == INT_TYPE){
          return node->evaluates_to_type;
        }
      }
      else if (node->operator == COMP_OP_R)
      {
        if (left_verif == right_verif && (right_verif == INT_TYPE || right_verif == BOOL_TYPE || left_verif == STRING_TYPE )){
          return node->evaluates_to_type;
        }
      }
      else if (node->operator == COMP_OP)
      {
        if ((right_verif == INT_TYPE || right_verif == BOOL_TYPE || right_verif == STRING_TYPE) && (left_verif == INT_TYPE || left_verif == BOOL_TYPE || left_verif == STRING_TYPE)){
          return node->evaluates_to_type;
        }
      }
    }
  }

}

int *check_compatibility ( int type_expected ) {
  return 1;
  // use the verify command, get the return type of the tree root
}

