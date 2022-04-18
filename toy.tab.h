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
     STRING_LITERAL = 278,
     EQU = 279,
     LTE = 280,
     GTE = 281,
     NEQ = 282,
     OB = 283,
     CB = 284,
     SEMICOLON = 285,
     NEGATE = 286,
     OP = 287,
     CP = 288,
     ADD = 289,
     SUB = 290,
     MUL = 291,
     DIV = 292,
     DOT = 293,
     COMMA = 294,
     ASSIGN = 295,
     LT = 296,
     GT = 297
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
#define STRING_LITERAL 278
#define EQU 279
#define LTE 280
#define GTE 281
#define NEQ 282
#define OB 283
#define CB 284
#define SEMICOLON 285
#define NEGATE 286
#define OP 287
#define CP 288
#define ADD 289
#define SUB 290
#define MUL 291
#define DIV 292
#define DOT 293
#define COMMA 294
#define ASSIGN 295
#define LT 296
#define GT 297




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 23 "toy.y"
{
  char* str;
  int val;
  Expression *expression;
}
/* Line 1529 of yacc.c.  */
#line 139 "toy.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

