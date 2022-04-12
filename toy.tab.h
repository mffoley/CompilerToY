/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BOOL = 258,
     TRUE = 259,
     FALSE = 260,
     VOID = 261,
     PRINTF = 262,
     STRUCT = 263,
     IF = 264,
     THEN = 265,
     ELSE = 266,
     FOR = 267,
     RETURN = 268,
     MOD = 269,
     INT = 270,
     AND = 271,
     OR = 272,
     NOT = 273,
     ID = 274,
     NUMBER = 275,
     STRING = 276,
     COMMENT = 277,
     EQU = 278,
     LTE = 279,
     GTE = 280,
     NEQ = 281,
     OB = 282,
     CB = 283,
     SEMICOLON = 284,
     NEGATE = 285,
     OP = 286,
     CP = 287,
     ADD = 288,
     SUB = 289,
     MUL = 290,
     DIV = 291,
     DOT = 292,
     COMMA = 293,
     ASSIGN = 294,
     LT = 295,
     GT = 296
   };
#endif
/* Tokens.  */
#define BOOL 258
#define TRUE 259
#define FALSE 260
#define VOID 261
#define PRINTF 262
#define STRUCT 263
#define IF 264
#define THEN 265
#define ELSE 266
#define FOR 267
#define RETURN 268
#define MOD 269
#define INT 270
#define AND 271
#define OR 272
#define NOT 273
#define ID 274
#define NUMBER 275
#define STRING 276
#define COMMENT 277
#define EQU 278
#define LTE 279
#define GTE 280
#define NEQ 281
#define OB 282
#define CB 283
#define SEMICOLON 284
#define NEGATE 285
#define OP 286
#define CP 287
#define ADD 288
#define SUB 289
#define MUL 290
#define DIV 291
#define DOT 292
#define COMMA 293
#define ASSIGN 294
#define LT 295
#define GT 296




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 22 "toy.y"
{
  char* str;
  int val;
  Expression *expression;
}
/* Line 1529 of yacc.c.  */
#line 137 "toy.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

