#include <stdio.h>
#include <string.h>

extern int INT_TYPE = 4;
extern int BOOL_TYPE = 5;
extern int STRING_TYPE = 6;
extern int VAR_STRUCT = 7;
extern int FIELD_STRUCT = 8;

extern int COMP_OP_R = 9;  // Comparison op (Restrictive)
extern int COMP_OP_NR = 10;  // Comparison op (Not Restrictive)
extern int M_OP = 11;    // Maths op

extern int BEXP = 12;  // Binary op
extern int UEXP = 13;  // Unary op
extern int NEXP = 14;  // Not an op


struct Expression {
  int evaluates_to_type;
  int op;
  int exp_type;
  struct Expression *lexp;
  struct Expression *rexp;
};

typedef struct Expression Expression;

//Use check_scope sym table for types

// For variables and types, just put their type into evaluates to... and use nexp

// Are there any operations that can evaluate to multiple types?  - can use the op type

// Function to check expected type vs the actual return type

// For return, check the symbol table for the current func

// Assignment not handled in here

Expression* add_expression (int type, int op, int exp, Expression *lexp, Expression *rexp);
void print (Expression *node);
void printtree (int indent, Expression *exp);
int *verify (Expression *node);

int *check_compatibility ( int type_expected, Expression *root );



Expression* add_expression (int type, int op, int exp, Expression *lexp, Expression *rexp) {

  Expression* next_expression = (Expression *)malloc(sizeof(Expression));
  next_expression->evaluates_to_type = type;
  next_expression->exp_type = exp;
  next_expression->op = op;

  next_expression->rexp = rexp;
  next_expression->lexp = lexp;

  return next_expression;
}


void print (Expression *node) {
  printtree (0,node);
}

void printtree (int indent, Expression *exp) {
  //traverse down
  if (exp != NULL){
    for (int i = 0; i < indent; i++){ printf("/t");}
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
int *verify (Expression *node) {
  // Do all verification steps - work to bottom of all expressions until two literals, work back up 
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
      if (node->op == M_OP)
      {
        if (left_verif == INT_TYPE && right_verif == INT_TYPE){
          return node->evaluates_to_type;
        }
      }
      else if (node->op == COMP_OP_R)
      {
        if (left_verif == right_verif && (right_verif == INT_TYPE || right_verif == BOOL_TYPE || left_verif == STRING_TYPE )){
          return node->evaluates_to_type;
        }
      }
      else if (node->op == COMP_OP_NR)
      {
        if ((right_verif == INT_TYPE || right_verif == BOOL_TYPE || right_verif == STRING_TYPE) && (left_verif == INT_TYPE || left_verif == BOOL_TYPE || left_verif == STRING_TYPE)){
          return node->evaluates_to_type;
        }
      }
    }
  }

}

int *check_compatibility ( int type_expected, Expression *root ) {
  if (verify(root) == type_expected){
    return 1;
  }
  return 0;
  // use the verify command, get the return type of the tree root
}

