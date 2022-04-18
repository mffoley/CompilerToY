/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 2 "toy.y"

  #include <stdio.h>

  int yylex();
  int yyerror(const char *msg);

  #include <stdlib.h>
  #include <string.h>
  #include "sym.h"
  #include "ast.h"
  #include "ast.c"


  int printg(){
    printf("blah");
    return 0;
  }




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 23 "toy.y"
{
  char* str;
  int val;
  Expression *expression;
}
/* Line 193 of yacc.c.  */
#line 207 "toy.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 220 "toy.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   281

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNRULES -- Number of states.  */
#define YYNSTATES  117

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    10,    11,    14,    17,
      20,    23,    24,    28,    32,    36,    40,    42,    44,    46,
      48,    50,    52,    54,    56,    58,    60,    62,    64,    66,
      68,    70,    72,    74,    76,    78,    80,    82,    84,    86,
      89,    93,    95,    97,   103,   105,   109,   111,   113,   115,
     127,   136,   143,   152,   158,   162,   166,   170,   175,   176,
     179,   181
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    -1,    44,    45,    -1,    -1,    47,    -1,
      -1,    66,    46,    -1,    58,    46,    -1,    66,    46,    -1,
      58,    47,    -1,    -1,    32,    48,    33,    -1,    48,    52,
      48,    -1,    48,    53,    48,    -1,    48,    54,    48,    -1,
      49,    -1,    50,    -1,    51,    -1,    19,    -1,    20,    -1,
      23,    -1,     4,    -1,     5,    -1,    34,    -1,    36,    -1,
      37,    -1,    35,    -1,    14,    -1,    25,    -1,    26,    -1,
      41,    -1,    42,    -1,    24,    -1,    27,    -1,    15,    -1,
       3,    -1,    21,    -1,    19,    -1,    55,    19,    -1,    56,
      39,    56,    -1,    55,    -1,     6,    -1,     8,    65,    28,
      56,    29,    -1,    19,    -1,    19,    38,    59,    -1,    10,
      -1,    11,    -1,    12,    -1,    62,    32,    19,    40,    48,
      30,    48,    30,    63,    33,    63,    -1,    62,    32,    30,
      48,    30,    63,    33,    63,    -1,     9,    32,    48,    33,
      60,    63,    -1,     9,    32,    48,    33,    60,    63,    61,
      63,    -1,     7,    32,    48,    33,    30,    -1,    13,    48,
      30,    -1,    28,    64,    29,    -1,    55,    19,    30,    -1,
      59,    40,    48,    30,    -1,    -1,    63,    64,    -1,    19,
      -1,    57,    65,    32,    56,    33,    28,    64,    29,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    58,    61,    62,    65,    66,    67,    70,
      71,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      86,    89,    92,    92,    95,    96,    97,    98,    99,   104,
     105,   106,   107,   110,   111,   115,   116,   117,   118,   121,
     122,   127,   127,   130,   134,   135,   139,   142,   145,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   158,   159,
     162,   165
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOL", "TRUE", "FALSE", "VOID",
  "PRINTF", "STRUCT", "IF", "THEN", "ELSE", "FOR", "RETURN", "MOD", "INT",
  "AND", "OR", "NOT", "ID", "NUMBER", "STRING", "COMMENT",
  "STRING_LITERAL", "EQU", "LTE", "GTE", "NEQ", "OB", "CB", "SEMICOLON",
  "NEGATE", "OP", "CP", "ADD", "SUB", "MUL", "DIV", "DOT", "COMMA",
  "ASSIGN", "LT", "GT", "$accept", "input", "line", "pgm2", "pgm", "exp",
  "int_literal", "string_literal", "bool_literal", "binary_maths_op",
  "binary_boolean_op_r", "binary_boolean_op_nr", "type", "declaration",
  "return_type", "struct_", "l_exp", "intern_scope_then",
  "intern_scope_else", "FOR_LOOP", "stmt", "stmt_seq", "Name", "proc", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    46,    46,    46,    47,
      47,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      49,    50,    51,    51,    52,    52,    52,    52,    52,    53,
      53,    53,    53,    54,    54,    55,    55,    55,    55,    56,
      56,    57,    57,    58,    59,    59,    60,    61,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    64,
      65,    66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     1,     0,     2,     2,     2,
       2,     0,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     1,     5,     1,     3,     1,     1,     1,    11,
       8,     6,     8,     5,     3,     3,     3,     4,     0,     2,
       1,     8
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    36,    42,     0,    35,    38,    37,     3,
       5,    41,     0,     0,     6,    60,     0,     0,    10,     9,
       6,     6,     0,     0,     8,     7,     0,     0,     0,    39,
      43,     0,     0,    40,    58,     0,     0,    48,    11,    38,
      58,     0,     0,     0,    58,     0,    11,    11,    22,    23,
      19,    20,    21,    11,     0,    16,    17,    18,     0,     0,
       0,    11,     0,    59,    61,     0,     0,     0,    28,    33,
      29,    30,    34,    54,    24,    27,    25,    26,    31,    32,
      11,    11,    11,    44,    45,    55,    56,     0,     0,    11,
       0,     0,    12,    13,    14,    15,    57,    11,     0,    53,
      46,     0,     0,     0,    51,    11,     0,    47,     0,     0,
       0,    52,     0,    50,     0,     0,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     9,    19,    10,    54,    55,    56,    57,    80,
      81,    82,    41,    27,    12,    20,    42,   101,   108,    43,
      44,    45,    16,    21
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -47
static const yytype_int16 yypact[] =
{
     -47,   239,   -47,   -47,   -47,    18,   -47,   -47,   -47,   -47,
     -47,   -47,    18,   258,   258,   -47,    12,     9,   -47,   -47,
     258,   258,    29,    29,   -47,   -47,    27,   -23,     6,   -47,
     -47,    29,    19,    10,   231,    24,    25,   -47,    -1,   -14,
     231,    41,    26,    35,   231,    39,    -1,    -1,   -47,   -47,
     -47,   -47,   -47,    -1,    28,   -47,   -47,   -47,    56,    48,
      46,    -1,    -7,   -47,   -47,    47,    71,    95,   -47,   -47,
     -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
      -1,    -1,    -1,    40,   -47,   -47,   -47,   119,    50,    -1,
      49,    76,   -47,   195,   195,   195,   -47,    -1,   138,   -47,
     -47,   231,   157,   231,    80,    -1,    54,   -47,   231,   176,
     231,   -47,   231,   -47,    59,   231,   -47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -47,   -47,   -47,   -10,    81,   -46,   -47,   -47,   -47,   -47,
     -47,   -47,     7,     2,   -47,     1,    42,   -47,   -47,   -47,
     166,   -31,    87,     4
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -45
static const yytype_int8 yytable[] =
{
      65,    66,    13,    48,    49,    14,    30,    67,    11,    59,
      24,    25,    88,    63,    13,    87,    31,    14,    50,    51,
      11,    11,    52,    89,    58,    28,   -44,    11,    11,    26,
      26,    53,     3,    33,    93,    94,    95,    15,    26,    32,
      22,    23,    68,    98,     6,    31,    29,    34,     7,    31,
       8,   102,    69,    70,    71,    72,    46,    47,    73,   109,
      60,    68,    74,    75,    76,    77,    61,    62,    64,    78,
      79,    69,    70,    71,    72,    83,    86,    85,    58,    99,
      90,    74,    75,    76,    77,    68,   100,   110,    78,    79,
      97,   107,   115,     0,    18,    69,    70,    71,    72,    17,
      84,     0,     0,     0,    91,    74,    75,    76,    77,    68,
       0,     0,    78,    79,     0,     0,     0,     0,     0,    69,
      70,    71,    72,     0,     0,     0,     0,     0,    92,    74,
      75,    76,    77,    68,     0,     0,    78,    79,     0,     0,
       0,     0,     0,    69,    70,    71,    72,     0,     0,    96,
       0,     0,    68,    74,    75,    76,    77,     0,     0,     0,
      78,    79,    69,    70,    71,    72,     0,     0,   103,     0,
       0,    68,    74,    75,    76,    77,     0,     0,     0,    78,
      79,    69,    70,    71,    72,     0,     0,   105,     0,     0,
      68,    74,    75,    76,    77,     0,     0,     0,    78,    79,
      69,    70,    71,    72,     0,     0,   112,     0,     0,    68,
      74,    75,    76,    77,     0,     0,     0,    78,    79,    69,
      70,    71,    72,     0,     0,     0,     0,     0,     0,    74,
      75,    76,    77,     0,     3,     0,    78,    79,    35,     2,
      36,     0,     3,    37,    38,     4,     6,     5,     0,     0,
      39,     0,     8,     0,     6,     0,     0,     0,     7,    40,
       8,     3,     0,     0,     4,     0,     5,   104,     0,   106,
       0,     0,     0,     6,   111,     0,   113,     7,   114,     8,
       0,   116
};

static const yytype_int8 yycheck[] =
{
      46,    47,     1,     4,     5,     1,    29,    53,     1,    40,
      20,    21,    19,    44,    13,    61,    39,    13,    19,    20,
      13,    14,    23,    30,    38,    23,    40,    20,    21,    22,
      23,    32,     3,    31,    80,    81,    82,    19,    31,    33,
      28,    32,    14,    89,    15,    39,    19,    28,    19,    39,
      21,    97,    24,    25,    26,    27,    32,    32,    30,   105,
      19,    14,    34,    35,    36,    37,    40,    32,    29,    41,
      42,    24,    25,    26,    27,    19,    30,    29,    38,    30,
      33,    34,    35,    36,    37,    14,    10,    33,    41,    42,
      40,    11,    33,    -1,    13,    24,    25,    26,    27,    12,
      58,    -1,    -1,    -1,    33,    34,    35,    36,    37,    14,
      -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    14,    -1,    -1,    41,    42,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    30,
      -1,    -1,    14,    34,    35,    36,    37,    -1,    -1,    -1,
      41,    42,    24,    25,    26,    27,    -1,    -1,    30,    -1,
      -1,    14,    34,    35,    36,    37,    -1,    -1,    -1,    41,
      42,    24,    25,    26,    27,    -1,    -1,    30,    -1,    -1,
      14,    34,    35,    36,    37,    -1,    -1,    -1,    41,    42,
      24,    25,    26,    27,    -1,    -1,    30,    -1,    -1,    14,
      34,    35,    36,    37,    -1,    -1,    -1,    41,    42,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    -1,     3,    -1,    41,    42,     7,     0,
       9,    -1,     3,    12,    13,     6,    15,     8,    -1,    -1,
      19,    -1,    21,    -1,    15,    -1,    -1,    -1,    19,    28,
      21,     3,    -1,    -1,     6,    -1,     8,   101,    -1,   103,
      -1,    -1,    -1,    15,   108,    -1,   110,    19,   112,    21,
      -1,   115
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,     0,     3,     6,     8,    15,    19,    21,    45,
      47,    55,    57,    58,    66,    19,    65,    65,    47,    46,
      58,    66,    28,    32,    46,    46,    55,    56,    56,    19,
      29,    39,    33,    56,    28,     7,     9,    12,    13,    19,
      28,    55,    59,    62,    63,    64,    32,    32,     4,     5,
      19,    20,    23,    32,    48,    49,    50,    51,    38,    64,
      19,    40,    32,    64,    29,    48,    48,    48,    14,    24,
      25,    26,    27,    30,    34,    35,    36,    37,    41,    42,
      52,    53,    54,    19,    59,    29,    30,    48,    19,    30,
      33,    33,    33,    48,    48,    48,    30,    40,    48,    30,
      10,    60,    48,    30,    63,    30,    63,    11,    61,    48,
      33,    63,    30,    63,    63,    33,    63
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 58 "toy.y"
    {;}
    break;

  case 5:
#line 62 "toy.y"
    {;}
    break;

  case 7:
#line 66 "toy.y"
    { if((yyvsp[(1) - (2)].val) == 1){printf("-----------------------------Valid Proc\n");} else {printf("-----------------------------Invalid Proc\n"); };}
    break;

  case 8:
#line 67 "toy.y"
    { if((yyvsp[(1) - (2)].val) == 1){printf("-----------------------------Valid Struct\n");} else {printf("-----------------------------Invalid Struct\n"); };}
    break;

  case 9:
#line 70 "toy.y"
    { if((yyvsp[(1) - (2)].val) == 1){printf("-----------------------------Valid Proc\n");} else {printf("-----------------------------Invalid Proc\n"); } ;}
    break;

  case 10:
#line 71 "toy.y"
    { if((yyvsp[(1) - (2)].val) == 1){printf("-----------------------------Valid Struct\n");} else {printf("-----------------------------Invalid Struct\n"); } ;}
    break;

  case 11:
#line 75 "toy.y"
    { (yyval.expression) = NULL; ;}
    break;

  case 12:
#line 76 "toy.y"
    {(yyval.expression) = (yyvsp[(2) - (3)].expression); ;}
    break;

  case 13:
#line 77 "toy.y"
    { (yyval.expression) = add_expression(4,11,12,(yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)); ;}
    break;

  case 14:
#line 78 "toy.y"
    { (yyval.expression) = add_expression(5,10,12,(yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)); ;}
    break;

  case 15:
#line 79 "toy.y"
    { (yyval.expression) = add_expression(5,10,12,(yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)); ;}
    break;

  case 16:
#line 80 "toy.y"
    { (yyval.expression) = add_expression(4,14,14,NULL,NULL); ;}
    break;

  case 17:
#line 81 "toy.y"
    { (yyval.expression) = add_expression(6,14,14,NULL,NULL); ;}
    break;

  case 18:
#line 82 "toy.y"
    { (yyval.expression) = add_expression(5,14,14,NULL,NULL); ;}
    break;

  case 19:
#line 83 "toy.y"
    { (yyval.expression) = add_expression(return_type((yyvsp[(1) - (1)].str)),14,14,NULL,NULL); ;}
    break;

  case 20:
#line 86 "toy.y"
    {if((yyvsp[(1) - (1)].val) >= 32768 || (yyvsp[(1) - (1)].val) < -32768 ) {printf("too big int");(yyval.val) = 0;} else{(yyval.val) = 1;};}
    break;

  case 21:
#line 89 "toy.y"
    {(yyval.val) = 1;;}
    break;

  case 22:
#line 92 "toy.y"
    {(yyval.val) = 1;;}
    break;

  case 23:
#line 92 "toy.y"
    {(yyval.val) = 1;;}
    break;

  case 24:
#line 95 "toy.y"
    {(yyval.val) = 1;;}
    break;

  case 25:
#line 96 "toy.y"
    {(yyval.val) = 1;;}
    break;

  case 26:
#line 97 "toy.y"
    {(yyval.val) = 1;;}
    break;

  case 27:
#line 98 "toy.y"
    {(yyval.val) = 1;;}
    break;

  case 28:
#line 99 "toy.y"
    {(yyval.val) = 1;;}
    break;

  case 29:
#line 104 "toy.y"
    {(yyval.val) = 1;;}
    break;

  case 30:
#line 105 "toy.y"
    {(yyval.val) = 1;;}
    break;

  case 31:
#line 106 "toy.y"
    {(yyval.val) = 1;;}
    break;

  case 32:
#line 107 "toy.y"
    {(yyval.val) = 1;;}
    break;

  case 33:
#line 110 "toy.y"
    {(yyval.val) = 1;;}
    break;

  case 34:
#line 111 "toy.y"
    {(yyval.val) = 1;;}
    break;

  case 35:
#line 115 "toy.y"
    { (yyval.val) = 4; ;}
    break;

  case 36:
#line 116 "toy.y"
    { (yyval.val) = 5; ;}
    break;

  case 37:
#line 117 "toy.y"
    { (yyval.val) = 6; ;}
    break;

  case 38:
#line 118 "toy.y"
    {store_struct_name(strtok((yyvsp[(1) - (1)].str), " ")); (yyval.val) = 7; ;}
    break;

  case 39:
#line 121 "toy.y"
    {if((yyvsp[(1) - (2)].val) != 0) { if(add_to_scope((yyvsp[(1) - (2)].val), (yyvsp[(2) - (2)].str)) == 1){ (yyval.val) = 1; if((yyvsp[(1) - (2)].val) == 7) {add_struct_name();} } else { (yyval.val) = 0;} } else {(yyval.val) = 0;};}
    break;

  case 40:
#line 122 "toy.y"
    { if((yyvsp[(1) - (3)].val) == 0 || (yyvsp[(3) - (3)].val) == 0) { (yyval.val) = 0; } else {(yyval.val) = 1;}  ;}
    break;

  case 43:
#line 130 "toy.y"
    { is_struct(1); new_scope(); if((yyvsp[(4) - (5)].val) == 1 && (yyvsp[(2) - (5)].val) == 1){ (yyval.val) = 1; } else {(yyval.val) = 0;}  ;}
    break;

  case 44:
#line 134 "toy.y"
    { printf("checking scope %s\n",(yyvsp[(1) - (1)].str)); printf("\ncheck scope response: %d \n",check_scope(strtok((yyvsp[(1) - (1)].str), " ="))); if(check_scope(strtok((yyvsp[(1) - (1)].str), " =")) == 1) { printf("return %d\n",return_type(strtok((yyvsp[(1) - (1)].str), " ="))); (yyval.val)=return_type(strtok((yyvsp[(1) - (1)].str), " ="));} ;}
    break;

  case 45:
#line 135 "toy.y"
    { printf("checking scope\n"); if((check_scope(strtok((yyvsp[(1) - (3)].str), ".")) == 1) ) { printf("Is a Struct\n"); } (yyval.val)=1;;}
    break;

  case 46:
#line 139 "toy.y"
    {add_internal_scope(); ;}
    break;

  case 47:
#line 142 "toy.y"
    { delete_scope(); add_internal_scope(); ;}
    break;

  case 48:
#line 145 "toy.y"
    { add_internal_scope(); ;}
    break;

  case 49:
#line 147 "toy.y"
    { delete_scope(); if(check_scope(strtok((yyvsp[(3) - (11)].str), " =")) == 1 && (yyvsp[(9) - (11)].val) == 1 && (yyvsp[(11) - (11)].val) == 1 && check_compatibility( 5, (yyvsp[(7) - (11)].expression) )==1 && check_compatibility(return_type((yyvsp[(3) - (11)].str)), (yyvsp[(5) - (11)].expression))) { (yyval.val) = 1; } else { (yyval.val) = 0; } ;}
    break;

  case 50:
#line 148 "toy.y"
    { delete_scope(); if( (yyvsp[(6) - (8)].val) == 1 && (yyvsp[(8) - (8)].val) == 1 && check_compatibility( 5, (yyvsp[(4) - (8)].expression) )==1 ) { (yyval.val) = 1; } else { (yyval.val) = 0; } ;}
    break;

  case 51:
#line 149 "toy.y"
    { delete_scope();  print((yyvsp[(3) - (6)].expression)); if(check_compatibility( 5, (yyvsp[(3) - (6)].expression) )==1){printf("If statement exp is bool\n");}else{printf("If statement exp is NOT bool\n");} if((yyvsp[(6) - (6)].val) == 0) { (yyval.val) = 0; } else { (yyval.val) = 1; } ;}
    break;

  case 52:
#line 150 "toy.y"
    { delete_scope(); if((yyvsp[(6) - (8)].val) == 0 || (yyvsp[(8) - (8)].val) == 0 || check_compatibility( 5, (yyvsp[(3) - (8)].expression) )==0) { (yyval.val) = 0; } else { (yyval.val) = 1; } ;}
    break;

  case 53:
#line 151 "toy.y"
    { (yyval.val) = check_compatibility(6,(yyvsp[(3) - (5)].expression)); ;}
    break;

  case 54:
#line 152 "toy.y"
    { (yyval.val) = 1; ;}
    break;

  case 55:
#line 153 "toy.y"
    { (yyval.val) = (yyvsp[(2) - (3)].val); ;}
    break;

  case 56:
#line 154 "toy.y"
    { printf("has returned with %d %s\n", (yyvsp[(1) - (3)].val), (yyvsp[(2) - (3)].str)); if((yyvsp[(1) - (3)].val) == 0 || add_to_scope((yyvsp[(1) - (3)].val), (yyvsp[(2) - (3)].str)) == 0) { (yyval.val) = 0; } else { (yyval.val) = 1; if((yyvsp[(1) - (3)].val) == 7) {   printf("HEREEEEEEEEEEEEEE");add_struct_name();}} ;}
    break;

  case 57:
#line 155 "toy.y"
    {  if( check_compatibility((yyvsp[(1) - (4)].val), (yyvsp[(3) - (4)].expression)) == 1){ (yyval.val) = 1; } else { (yyval.val) = 0; };}
    break;

  case 59:
#line 159 "toy.y"
    { if((yyvsp[(1) - (2)].val) == 0 || (yyvsp[(2) - (2)].val) == 0) { (yyval.val) = 0; } else { (yyval.val) = 1;};}
    break;

  case 60:
#line 162 "toy.y"
    { if(add_name((yyvsp[(1) - (1)].str)) == 1){ (yyval.val) = 1; } else {(yyval.val) = 0;} ;}
    break;

  case 61:
#line 165 "toy.y"
    { new_scope(); if((yyvsp[(4) - (8)].val) == 1 && (yyvsp[(2) - (8)].val) == 1 && (yyvsp[(7) - (8)].val) == 1){ (yyval.val) = 1; } else {(yyval.val) = 0;};}
    break;


/* Line 1267 of yacc.c.  */
#line 1820 "toy.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 168 "toy.y"


 main()
{
    extern FILE *yyin, yyout;
    
    yyin = fopen("Test2.txt", "r");

    int parse = yyparse();
    // if(parse == 0) printf ("Error\n");
    // else printf("Valid");
}

int yyerror(const char *msg){
  fprintf(stderr, "%s\n", msg);
  return 0;
}

