#include <stdio.h>
#include <string.h>

int INT_TYPE = 4;
int BOOL_TYPE = 5;
int STRING_TYPE = 6;
int VAR_STRUCT = 7;
int FIELD_STRUCT = 8;

int COMP_OP_R = 9;  // Comparison op (Restrictive)
int COMP_OP_NR = 10;  // Comparison op (Not Restrictive)
int M_OP = 11;    // Maths op

int BEXP = 12;  // Binary op
int UEXP = 13;  // Unary op
int NEXP = 14;  // Not an op

// typedef struct Expression {
//   int evaluates_to_type;
//   int op;
//   int exp_type;
//   struct Expression *lexp;
//   struct Expression *rexp;
// } Expression;


Expression* add_expression (int type, int op, int exp, Expression *lexp, Expression *rexp, char *sname) {
  //printf("adding %d\n",type);
  Expression* next_expression = (Expression *)malloc(sizeof(Expression));
  next_expression->evaluates_to_type = type;
  next_expression->exp_type = exp;
  next_expression->op = op;
  next_expression->sname = sname;

  next_expression->rexp = (Expression *)malloc(sizeof(Expression));
  next_expression->rexp = rexp;
  next_expression->lexp = (Expression *)malloc(sizeof(Expression));
  next_expression->lexp = lexp;
  //printf("done adding\n");
  return next_expression;
}


void print (Expression *node) {
  printf ("\nAST:\n");
  printtree (0,node);
  printf ("\n");
}

void printtree (int indent, Expression *exp) {
  //traverse down
  if (exp != NULL){
    for (int i = 0; i < indent; i++){ printf("     ");}
    if (exp->exp_type == BEXP){
      if (exp->op == M_OP){
        printf("Binary Maths Expression\n");
      }
      else{
        printf("Binary Boolean Expression\n");
      }
    }
    else if (exp->exp_type == UEXP){
      printf("Unary Expression\n");
    }
    else if (exp->exp_type == NEXP){
      if (exp->evaluates_to_type == INT_TYPE){
        printf("Int\n");
      }
      if (exp->evaluates_to_type == BOOL_TYPE){
        printf("Bool\n");
      }
      if (exp->evaluates_to_type == STRING_TYPE){
        printf("String\n");
      }
    }
  }
  if (exp->lexp != NULL){
    printtree(indent+1,exp->lexp);}
    if (exp->rexp != NULL){
  printtree(indent+1,exp->rexp);}
}

// Pass in null to start, returns the return type of the thing below it
int verify (Expression *node) {
  // Do all verification steps - work to bottom of all expressions until two literals, work back up 
  //printf("Verifying:\n");
  //print(node);
  //printf("\n\n");
  int left_verif;
  int right_verif;
  left_verif = -1;
  right_verif = -1;

  if (node->rexp != NULL && node->rexp->exp_type == NEXP){
    right_verif = node->rexp->evaluates_to_type;
    //printf("Right is not expression, right evaluates to %d\n",right_verif);
  }
  else if (node->rexp != NULL && (node->rexp->exp_type == UEXP || node->rexp->exp_type == BEXP)){
    //printf("Verifying right....\n");
    right_verif = verify(node->rexp);
  }

  if (node->lexp != NULL && node->lexp->exp_type == NEXP){
    left_verif = node->lexp->evaluates_to_type;
    //printf("Left is not expression, left evaluates to %d\n",left_verif);
  }
  else if (node->lexp != NULL && (node->lexp->exp_type == UEXP || node->lexp->exp_type == BEXP)){
    //printf("Verifying left....\n");
    left_verif = verify(node->lexp);
  }




  if (node->exp_type == UEXP) {
    if ( right_verif != -1){
    //printf("Left and right verified\n");
      if (node->op == M_OP)
      {
        if (right_verif == INT_TYPE){
          //printf("Left and right of maths operator evaluate to ints, returning %d\n",node->evaluates_to_type);
          return node->evaluates_to_type;
        }
      }
      else if (node->op == COMP_OP_R)
      {
        if (right_verif == BOOL_TYPE){
          return node->evaluates_to_type;
          //printf("Left and right of restrictive comparison evaluate to same, returning %d\n",node->evaluates_to_type);
        }
      }
    }

    
  }
  else if (node->exp_type == BEXP) {
    if (left_verif != -1 && right_verif != -1){
      if (node->op == M_OP)
      {
        if (left_verif == INT_TYPE && right_verif == INT_TYPE){
          //printf("Left and right of maths operator evaluate to ints, returning %d\n",node->evaluates_to_type);
          return node->evaluates_to_type;
        }
      }
      else if (node->op == COMP_OP_R)
      {
        if (left_verif == right_verif && (right_verif == INT_TYPE || right_verif == BOOL_TYPE || left_verif == STRING_TYPE || left_verif== VAR_STRUCT)){
          return node->evaluates_to_type;
          //printf("Left and right of restrictive comparison evaluate to same, returning %d\n",node->evaluates_to_type);
        }
      }
      else if (node->op == COMP_OP_NR)
      {
        if ((right_verif == INT_TYPE || right_verif == BOOL_TYPE || right_verif == STRING_TYPE || right_verif == VAR_STRUCT)  && (left_verif == INT_TYPE || left_verif == BOOL_TYPE || left_verif == STRING_TYPE || left_verif== VAR_STRUCT)){
          return node->evaluates_to_type;
        }
      }
    }

    
  }
  if (node->exp_type == NEXP){
      return node->evaluates_to_type;
    }
  //printf ("Verification failed, returning -1\n\n");
  return -1;

}


// Pass in null to start, returns the return type of the thing below it
ExpType* verify_dyn (Expression *node) {
  // Do all verification steps - work to bottom of all expressions until two literals, work back up 
  //printf("Verifying:\n");
  //print(node);
  ExpType* ret = (ExpType *)malloc(sizeof(ExpType));
  ExpType* left_verif = (ExpType *)malloc(sizeof(ExpType));
  ExpType* right_verif = (ExpType *)malloc(sizeof(ExpType));
  left_verif->type = -1;
  right_verif->type = -1;

  if (node->rexp != NULL && node->rexp->exp_type == NEXP){
    right_verif->type = node->rexp->evaluates_to_type;
    right_verif->sname = node->rexp->sname;
    //printf("Right is not expression, right evaluates to %d\n",right_verif);
  }
  else if (node->rexp != NULL && (node->rexp->exp_type == UEXP || node->rexp->exp_type == BEXP)){
    //printf("Verifying right....\n");
    right_verif = verify_dyn(node->rexp);
  }

  if (node->lexp != NULL && node->lexp->exp_type == NEXP){
    left_verif->type = node->lexp->evaluates_to_type;
    left_verif->sname = node->lexp->sname;
    //printf("Left is not expression, left evaluates to %d\n",left_verif);
  }
  else if (node->lexp != NULL && (node->lexp->exp_type == UEXP || node->lexp->exp_type == BEXP)){
    //printf("Verifying left....\n");
    left_verif = verify_dyn(node->lexp);
  }


  ret->type = node->evaluates_to_type;
  ret->sname = node->sname;

  if (node->exp_type == BEXP) {
    if (left_verif->type != NULL && right_verif->type != NULL){
    //printf("Left and right verified\n");
      if (node->op == M_OP)
      {
        if (left_verif->type == INT_TYPE && right_verif->type == INT_TYPE){
          //printf("Left and right of maths operator evaluate to ints, returning %d\n",node->evaluates_to_type);
          return ret;
        }
      }
      else if (node->op == COMP_OP_R)
      {
        if (left_verif->type == right_verif->type && (right_verif->type == INT_TYPE || right_verif->type == BOOL_TYPE || left_verif->type == STRING_TYPE || right_verif->type == VAR_STRUCT)){
          return ret;
          //printf("Left and right of restrictive comparison evaluate to same, returning %d\n",node->evaluates_to_type);
        }
      }
      else if (node->op == COMP_OP_NR)
      {
        if ((right_verif->type  == INT_TYPE|| right_verif->type == BOOL_TYPE || right_verif->type == STRING_TYPE || right_verif->type == VAR_STRUCT) && (left_verif->type == INT_TYPE || left_verif->type == BOOL_TYPE || left_verif->type == STRING_TYPE || left_verif->type == VAR_STRUCT)){
          return ret;
        }
      }
    }

    
  }


  else if (node->exp_type == UEXP) {
    if ( right_verif->type != NULL){
    //printf("Left and right verified\n");
      if (node->op == M_OP)
      {
        if (right_verif->type == INT_TYPE){
          //printf("Left and right of maths operator evaluate to ints, returning %d\n",node->evaluates_to_type);
          return ret;
        }
      }
      else if (node->op == COMP_OP_R)
      {
        if (right_verif->type == BOOL_TYPE){
          return ret;
          //printf("Left and right of restrictive comparison evaluate to same, returning %d\n",node->evaluates_to_type);
        }
      }
    }
  }

  if (node->exp_type == NEXP){
      return ret;
    }

  ret->type = -1;
  ret->sname = NULL;
  //printf ("Verification failed, returning -1\n\n");
  return ret;

}

int check_compatibility ( int type_expected, Expression *root ) {
  //printf("checking compatibility with type %d and expression (return type evaluated to be %d)\nVerifying:\n", type_expected, verify(root));
  //print(root);
  if (verify(root) == type_expected){
    return 1;
  }
  return 0;
  // use the verify command, get the return type of the tree root
}

int check_compatibility_dyn ( ExpType *type_expected, Expression *root, int overridesname) {
  int type = verify_dyn(root)->type;
  //printf("checking compatibility with type %d and expression (return type evaluated to be %d)\nVerifying:\n", type, verify_dyn(root)->type);
  
  char *name = verify_dyn(root)->sname;
  //printf ("Actual type is: %d , %s \n",type,name);
  printf ("Expected type is: %d , %s\n",type_expected->type, type_expected->sname);
  if ( (type == type_expected->type ) && ((type == 7 && (overridesname == 1 || (name != NULL && strcmp( type_expected->sname, name)== 0) )) || type != 7)){
    //printf("returning 1\n");
    return 1;
  }
  printf("returning 0 for compatibility\n");
  return 0;
  // use the verify command, get the return type of the tree root
}
