/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 33 "gpl.y" /* yacc.c:339  */
  // bison syntax to indicate the start of the header
    // the header is copied directly into y.tab.c (the generated parser)

#include "symbol_table.h"
#include "expression.h"

Symbol_table *my_table = Symbol_table::instance();
extern int yylex();               // this lexer function returns next token
extern int yyerror(const char *); // used to print errors
extern int line_count;            // current line in the input; from record.l

#include "error.h"      // class for printing errors (used by gpl)
#include "parser.h"
#include <iostream>
#include <string>
using namespace std;

// bison syntax to indicate the end of the header

#line 86 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 73 "gpl.y" /* yacc.c:355  */

  #include "expression.h" 
  #include "variable.h" 
  #include <sstream>

#line 122 "y.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_INT = 258,
    T_DOUBLE = 259,
    T_STRING = 260,
    T_TRIANGLE = 261,
    T_PIXMAP = 262,
    T_CIRCLE = 263,
    T_RECTANGLE = 264,
    T_TEXTBOX = 265,
    T_FORWARD = 266,
    T_INITIALIZATION = 267,
    T_TRUE = 268,
    T_FALSE = 269,
    T_TOUCHES = 270,
    T_NEAR = 271,
    T_ANIMATION = 272,
    T_IF = 273,
    T_FOR = 274,
    IF_NO_ELSE = 275,
    T_ELSE = 276,
    T_PRINT = 278,
    T_EXIT = 279,
    T_LPAREN = 280,
    T_RPAREN = 281,
    T_LBRACE = 282,
    T_RBRACE = 283,
    T_LBRACKET = 284,
    T_RBRACKET = 285,
    T_SEMIC = 286,
    T_COMMA = 287,
    T_PERIOD = 288,
    T_ASSIGN = 289,
    T_PLUS_ASSIGN = 290,
    T_MINUS_ASSIGN = 291,
    T_SIN = 292,
    T_COS = 293,
    T_TAN = 294,
    T_ASIN = 295,
    T_ACOS = 296,
    T_ATAN = 297,
    T_SQRT = 298,
    T_FLOOR = 299,
    T_ABS = 300,
    T_RANDOM = 301,
    T_NOT = 302,
    T_OR = 303,
    T_AND = 304,
    T_NOT_EQUAL = 305,
    T_EQUAL = 306,
    T_GREATER_EQUAL = 307,
    T_LESS_EQUAL = 308,
    T_GREATER = 309,
    T_LESS = 310,
    T_MINUS = 311,
    T_PLUS = 312,
    T_MOD = 313,
    T_DIVIDE = 314,
    T_ASTERISK = 315,
    T_ON = 316,
    T_SPACE = 317,
    T_LEFTARROW = 318,
    T_RIGHTARROW = 319,
    T_UPARROW = 320,
    T_DOWNARROW = 321,
    T_LEFTMOUSE_DOWN = 322,
    T_MIDDLEMOUSE_DOWN = 323,
    T_RIGHTMOUSE_DOWN = 324,
    T_LEFTMOUSE_UP = 325,
    T_MIDDLEMOUSE_UP = 326,
    T_RIGHTMOUSE_UP = 327,
    T_MOUSE_MOVE = 328,
    T_MOUSE_DRAG = 329,
    T_F1 = 330,
    T_AKEY = 331,
    T_SKEY = 332,
    T_DKEY = 333,
    T_FKEY = 334,
    T_HKEY = 335,
    T_JKEY = 336,
    T_KKEY = 337,
    T_LKEY = 338,
    T_WKEY = 339,
    T_ID = 340,
    T_INT_CONSTANT = 341,
    T_DOUBLE_CONSTANT = 342,
    T_STRING_CONSTANT = 343,
    T_ERROR = 344,
    UNARY_OPS = 345
  };
#endif
/* Tokens.  */
#define T_INT 258
#define T_DOUBLE 259
#define T_STRING 260
#define T_TRIANGLE 261
#define T_PIXMAP 262
#define T_CIRCLE 263
#define T_RECTANGLE 264
#define T_TEXTBOX 265
#define T_FORWARD 266
#define T_INITIALIZATION 267
#define T_TRUE 268
#define T_FALSE 269
#define T_TOUCHES 270
#define T_NEAR 271
#define T_ANIMATION 272
#define T_IF 273
#define T_FOR 274
#define IF_NO_ELSE 275
#define T_ELSE 276
#define T_PRINT 278
#define T_EXIT 279
#define T_LPAREN 280
#define T_RPAREN 281
#define T_LBRACE 282
#define T_RBRACE 283
#define T_LBRACKET 284
#define T_RBRACKET 285
#define T_SEMIC 286
#define T_COMMA 287
#define T_PERIOD 288
#define T_ASSIGN 289
#define T_PLUS_ASSIGN 290
#define T_MINUS_ASSIGN 291
#define T_SIN 292
#define T_COS 293
#define T_TAN 294
#define T_ASIN 295
#define T_ACOS 296
#define T_ATAN 297
#define T_SQRT 298
#define T_FLOOR 299
#define T_ABS 300
#define T_RANDOM 301
#define T_NOT 302
#define T_OR 303
#define T_AND 304
#define T_NOT_EQUAL 305
#define T_EQUAL 306
#define T_GREATER_EQUAL 307
#define T_LESS_EQUAL 308
#define T_GREATER 309
#define T_LESS 310
#define T_MINUS 311
#define T_PLUS 312
#define T_MOD 313
#define T_DIVIDE 314
#define T_ASTERISK 315
#define T_ON 316
#define T_SPACE 317
#define T_LEFTARROW 318
#define T_RIGHTARROW 319
#define T_UPARROW 320
#define T_DOWNARROW 321
#define T_LEFTMOUSE_DOWN 322
#define T_MIDDLEMOUSE_DOWN 323
#define T_RIGHTMOUSE_DOWN 324
#define T_LEFTMOUSE_UP 325
#define T_MIDDLEMOUSE_UP 326
#define T_RIGHTMOUSE_UP 327
#define T_MOUSE_MOVE 328
#define T_MOUSE_DRAG 329
#define T_F1 330
#define T_AKEY 331
#define T_SKEY 332
#define T_DKEY 333
#define T_FKEY 334
#define T_HKEY 335
#define T_JKEY 336
#define T_KKEY 337
#define T_LKEY 338
#define T_WKEY 339
#define T_ID 340
#define T_INT_CONSTANT 341
#define T_DOUBLE_CONSTANT 342
#define T_STRING_CONSTANT 343
#define T_ERROR 344
#define UNARY_OPS 345

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 80 "gpl.y" /* yacc.c:355  */

 int            union_int;
 double         union_double;
 std::string    *union_string;  // MUST be a pointer to a string (this sucks!)
 Expression     *union_expression;
 Variable       *union_variable;

#line 320 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 337 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   373

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  227

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   345

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   225,   225,   230,   231,   236,   237,   238,   243,   316,
     367,   368,   369,   374,   378,   386,   387,   392,   393,   394,
     395,   396,   401,   402,   407,   408,   413,   418,   423,   424,
     429,   430,   431,   436,   441,   441,   446,   451,   452,   453,
     454,   455,   460,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   492,   493,   498,   502,
     507,   513,   514,   519,   520,   521,   522,   523,   528,   529,
     534,   539,   544,   549,   550,   551,   556,   567,   603,   604,
     609,   610,   626,   642,   647,   652,   657,   662,   667,   672,
     678,   694,   710,   735,   757,   766,   776,   786,   791,   795,
     804,   808,   812,   816,   820,   828,   829,   834,   839,   844,
     849,   854,   859,   864,   869,   874,   879,   887
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"int\"", "\"double\"", "\"string\"",
  "\"triangle\"", "\"pixmap\"", "\"circle\"", "\"rectangle\"",
  "\"textbox\"", "\"forward\"", "\"initialization\"", "\"true\"",
  "\"false\"", "\"touches\"", "\"near\"", "\"animation\"", "\"if\"",
  "\"for\"", "IF_NO_ELSE", "T_ELSE", "\"else\"", "\"print\"", "\"exit\"",
  "\"(\"", "\")\"", "\"{\"", "\"}\"", "\"[\"", "\"]\"", "\";\"", "\",\"",
  "\".\"", "\"=\"", "\"+=\"", "\"-=\"", "\"sin\"", "\"cos\"", "\"tan\"",
  "\"asin\"", "\"acos\"", "\"atan\"", "\"sqrt\"", "\"floor\"", "\"abs\"",
  "\"random\"", "\"!\"", "\"||\"", "\"&&\"", "\"!=\"", "\"==\"", "\">=\"",
  "\"<=\"", "\">\"", "\"<\"", "\"-\"", "\"+\"", "\"%\"", "\"/\"", "\"*\"",
  "\"on\"", "\"space\"", "\"leftarrow\"", "\"rightarrow\"", "\"uparrow\"",
  "\"downarrow\"", "\"leftmouse_down\"", "\"middlemouse_down\"",
  "\"rightmouse_down\"", "\"leftmouse_up\"", "\"middlemouse_up\"",
  "\"rightmouse_up\"", "\"mouse_move\"", "\"mouse_drag\"", "\"f1\"",
  "\"akey\"", "\"skey\"", "\"dkey\"", "\"fkey\"", "\"hkey\"", "\"jkey\"",
  "\"kkey\"", "\"lkey\"", "\"wkey\"", "\"identifier\"", "\"int constant\"",
  "\"double constant\"", "\"string constant\"", "\"error\"", "UNARY_OPS",
  "$accept", "program", "declaration_list", "declaration",
  "variable_declaration", "simple_type", "optional_initializer",
  "object_declaration", "object_type", "parameter_list_or_empty",
  "parameter_list", "parameter", "forward_declaration", "block_list",
  "block", "initialization_block", "animation_block", "$@1",
  "animation_parameter", "check_animation_parameter", "on_block",
  "keystroke", "if_block", "statement_block", "statement_block_creator",
  "end_of_statement_block", "statement_list", "statement", "if_statement",
  "for_statement", "print_statement", "exit_statement", "assign_statement",
  "variable", "expression", "primary_expression", "geometric_operator",
  "math_operator", "empty", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345
};
# endif

#define YYPACT_NINF -193

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-193)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -193,    15,   348,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,     0,  -193,    -7,   -51,    32,   -39,    33,
       1,  -193,   -18,  -193,   -26,  -193,   -15,  -193,    44,   -16,
     255,  -193,  -193,  -193,  -193,    52,    12,    12,  -193,  -193,
      10,    12,  -193,  -193,    71,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,    44,    13,
    -193,  -193,    12,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,    12,    12,     2,  -193,  -193,  -193,    23,
     182,  -193,    77,   240,    73,    87,    83,  -193,  -193,   213,
    -193,    35,  -193,    31,    91,    80,  -193,  -193,    12,    36,
    -193,  -193,    38,  -193,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,  -193,
      10,  -193,   -12,  -193,    39,    41,    59,    60,    62,    92,
    -193,  -193,  -193,   226,  -193,  -193,   195,   290,   308,   308,
     313,   313,   313,   313,    16,    16,  -193,  -193,  -193,   116,
     240,  -193,    95,   125,   126,   127,  -193,  -193,  -193,  -193,
     122,   128,   130,    75,  -193,  -193,  -193,  -193,  -193,   131,
     124,  -193,    12,  -193,    12,    12,  -193,  -193,  -193,  -193,
      12,    12,    12,  -193,    78,   134,    38,   151,   169,   240,
     240,   240,  -193,  -193,    44,  -193,  -193,  -193,    42,   141,
    -193,     9,   147,  -193,    44,  -193,    12,  -193,  -193,  -193,
     256,  -193,    38,  -193,   153,    44,  -193
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     127,     0,   127,     4,     1,    10,    11,    12,    17,    18,
      19,    20,    21,     0,     3,     0,     0,     0,     0,     0,
       2,    29,     0,     5,   127,     6,     0,     7,     0,     0,
       0,    28,    30,    31,    32,     0,     0,     0,     8,    14,
     127,     0,    69,    33,     0,    43,    46,    47,    44,    45,
      48,    49,    50,    51,    52,    53,    54,    55,    65,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
     111,   112,     0,   117,   118,   119,   120,   121,   122,   123,
     125,   124,   126,     0,     0,    86,   110,   113,   114,   109,
       0,    90,     0,    13,     0,     0,    22,    25,    23,     0,
     127,     0,    42,     0,     0,     0,   105,   104,     0,     0,
     115,   116,     0,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,    16,     0,    72,     0,     0,     0,     0,     0,     0,
      36,    27,   108,     0,    88,   107,    91,    92,    98,    97,
      94,    93,    96,    95,   100,    99,   103,   102,   101,     0,
      26,    24,     0,     0,     0,     0,    70,    71,    73,    74,
       0,     0,     0,     0,    37,    38,    39,    40,    41,     0,
      87,   106,     0,    69,     0,     0,    68,    76,    77,    75,
       0,     0,     0,    34,     0,     0,     0,     0,     0,    83,
      84,    85,   127,    89,    69,    70,    81,    82,     0,    78,
      67,     0,     0,    70,    69,    70,     0,    35,    79,    66,
       0,    69,     0,    70,     0,     0,    80
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,   129,  -193,
    -193,    66,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,    -1,   -28,   -40,  -101,    14,     3,  -193,  -193,
    -193,  -193,  -192,  -103,   -36,  -193,  -193,  -193,   101
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    14,    15,    16,    38,    17,    18,    95,
      96,    97,    19,    20,    31,    32,    33,   202,   104,   139,
      34,    68,   209,   210,   211,   186,   132,   167,   168,   169,
     170,   171,   172,    89,    90,    91,   112,    92,   133
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      43,    93,   100,    36,   205,    99,   162,   163,    37,   145,
      40,   164,   165,    28,    41,     4,   166,    22,    29,     8,
       9,    10,    11,    12,    23,    70,    71,   162,   163,   173,
     223,   108,   164,   165,    24,   109,   105,    72,   110,   111,
     102,   134,   135,   136,   137,   138,    26,   106,   107,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
     162,   163,    30,    25,    27,   164,   165,    35,    84,    44,
     213,    42,   143,    85,   124,   125,   126,    69,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   173,    85,    94,   101,    85,    86,    87,
      88,     3,   127,    21,   212,   173,   142,   128,   173,   190,
     191,   192,   217,   129,   219,   130,   140,   141,   179,   173,
     182,   144,   224,    85,   174,    39,   175,    85,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    98,   181,   196,   176,   177,   195,   178,   197,   198,
     183,   184,   185,   187,   199,   200,   201,   194,   193,   188,
     204,   189,   214,   203,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   206,   216,   225,
     220,   222,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   207,   161,   226,   103,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   113,   218,   215,     0,   208,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   131,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   180,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   221,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,     5,     6,     7,     8,     9,    10,    11,    12,    13,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   122,
     123,   124,   125,   126
};

static const yytype_int16 yycheck[] =
{
      28,    37,    42,    29,   196,    41,    18,    19,    34,   112,
      25,    23,    24,    12,    29,     0,    28,    17,    17,     6,
       7,     8,     9,    10,    31,    13,    14,    18,    19,   132,
     222,    29,    23,    24,    85,    33,    72,    25,    15,    16,
      68,     6,     7,     8,     9,    10,    85,    83,    84,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      18,    19,    61,    31,    31,    23,    24,    85,    56,    85,
      28,    27,   108,    85,    58,    59,    60,    25,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   196,    85,    85,    25,    85,    86,    87,
      88,     0,    25,     2,   205,   208,    26,    34,   211,    34,
      35,    36,   213,    26,   215,    32,    85,    26,    26,   222,
      25,    85,   223,    85,    85,    24,    85,    85,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    40,    26,   183,    85,    85,   182,    85,   184,   185,
      25,    25,    25,    31,   190,   191,   192,    33,    27,    31,
      26,    31,    21,    85,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    26,    31,    26,
     216,   221,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    26,   130,   225,    69,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    30,   214,   211,    -1,   202,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    30,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    30,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    31,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    56,
      57,    58,    59,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    92,    93,   129,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    94,    95,    96,    98,    99,   103,
     104,   129,    17,    31,    85,    31,    85,    31,    12,    17,
      61,   105,   106,   107,   111,    85,    29,    34,    97,   129,
      25,    29,    27,   114,    85,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,   112,    25,
      13,    14,    25,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    56,    85,    86,    87,    88,   124,
     125,   126,   128,   125,    85,   100,   101,   102,   129,   125,
     115,    25,   114,    99,   109,   125,   125,   125,    29,    33,
      15,    16,   127,    30,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    25,    34,    26,
      32,    30,   117,   129,     6,     7,     8,     9,    10,   110,
      85,    26,    26,   125,    85,   124,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   102,    18,    19,    23,    24,    28,   118,   119,   120,
     121,   122,   123,   124,    85,    85,    85,    85,    85,    26,
      30,    26,    25,    25,    25,    25,   116,    31,    31,    31,
      34,    35,    36,    27,    33,   125,   115,   125,   125,   125,
     125,   125,   108,    85,    26,   123,    26,    26,   117,   113,
     114,   115,   116,    28,    21,   118,    31,   116,   113,   116,
     125,    31,   115,   123,   116,    26,   114
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    93,    93,    94,    94,    94,    95,    95,
      96,    96,    96,    97,    97,    98,    98,    99,    99,    99,
      99,    99,   100,   100,   101,   101,   102,   103,   104,   104,
     105,   105,   105,   106,   108,   107,   109,   110,   110,   110,
     110,   110,   111,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   113,   113,   114,   115,
     116,   117,   117,   118,   118,   118,   118,   118,   119,   119,
     120,   121,   122,   123,   123,   123,   124,   124,   124,   124,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   126,   126,
     126,   126,   126,   126,   126,   127,   127,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   129
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     2,     2,     2,     3,     5,
       1,     1,     1,     2,     1,     5,     5,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     6,     2,     1,
       1,     1,     1,     2,     0,    10,     2,     2,     2,     2,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     5,     0,
       0,     2,     1,     1,     1,     2,     2,     2,     5,     7,
      13,     4,     4,     3,     3,     3,     1,     4,     3,     6,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     4,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 8:
#line 243 "gpl.y" /* yacc.c:1661  */
    {
    if((yyvsp[-2].union_int) == T_INT){
        int initial_value = 0;
        if((yyvsp[0].union_expression) != NULL){
            if((yyvsp[0].union_expression)->get_type() != INT){
                if((yyvsp[0].union_expression)->get_type() == DOUBLE){
                    Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE, "double", *(yyvsp[-1].union_string), "int");
                }
                else if((yyvsp[0].union_expression)->get_type() == STRING){
                    Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE, "string", *(yyvsp[-1].union_string), "int");
                }
            }
            else{
                initial_value = (yyvsp[0].union_expression)->eval_int();
            }
        }

        //Insert symbol into the table
        Symbol *s = my_table->lookup(*((yyvsp[-1].union_string)));
        if(s==NULL){
            Symbol *s = new Symbol;
            s->type = INT;
            s->name = *((yyvsp[-1].union_string));
            s->value = new V(initial_value);
            my_table->insert(*(yyvsp[-1].union_string),s);
        }
        else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *((yyvsp[-1].union_string)));
        }
    }
    else if((yyvsp[-2].union_int) == T_STRING){
        string initial_value = "";
        if((yyvsp[0].union_expression) != NULL){
            initial_value = (yyvsp[0].union_expression)->eval_string();   
        }

        Symbol *s = my_table->lookup(*((yyvsp[-1].union_string)));
        if(s==NULL){
            Symbol *s = new Symbol;
            s->type = STRING;
            s->name = *((yyvsp[-1].union_string));
            s->value = new V(initial_value);
            my_table->insert(*(yyvsp[-1].union_string),s);
        }
        else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *((yyvsp[-1].union_string)));
        }
    }
    else if((yyvsp[-2].union_int) == T_DOUBLE){
        double initial_value = 0.0;
        if((yyvsp[0].union_expression) != NULL){
            if((yyvsp[0].union_expression)->get_type() == STRING){
                Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE,"string",*(yyvsp[-1].union_string),"double");
            }
            else{
                initial_value = (yyvsp[0].union_expression)->eval_double();
            }
        }


        Symbol *s = my_table->lookup(*((yyvsp[-1].union_string)));
        if(s==NULL){
            Symbol *s = new Symbol;
            s->type = DOUBLE;
            s->name = *((yyvsp[-1].union_string));
            s->value = new V(initial_value);
            my_table->insert(*(yyvsp[-1].union_string),s);
        }
        else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *((yyvsp[-1].union_string)));
        }
    }
}
#line 1700 "y.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 316 "gpl.y" /* yacc.c:1661  */
    {
    if((yyvsp[-1].union_expression)->get_type() != INT){
        Error::error(Error::INVALID_ARRAY_SIZE, *(yyvsp[-3].union_string), (yyvsp[-1].union_expression)->eval_string());
    }
    else if((yyvsp[-1].union_expression)->eval_int() <= 0){
        Error::error(Error::INVALID_ARRAY_SIZE, *(yyvsp[-3].union_string), (yyvsp[-1].union_expression)->eval_string());     
    }
    else if((yyvsp[-4].union_int) == T_INT){
        Symbol *s = my_table->lookup(*((yyvsp[-3].union_string)));
        if(s==NULL){
            Symbol *s = new Symbol;
            s->type = INT_ARRAY;
            s->name = *((yyvsp[-3].union_string));
            s->value = new V(INT_ARRAY, (yyvsp[-1].union_expression)->eval_int());     
            my_table->insert(*((yyvsp[-3].union_string)),s);
        }
        else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *((yyvsp[-3].union_string)));
        }
    }
    else if((yyvsp[-4].union_int) == T_STRING){
        Symbol *s = my_table->lookup(*((yyvsp[-3].union_string)));
        if(s==NULL){
            Symbol *s = new Symbol;
            s->type = STRING_ARRAY;
            s->name = *((yyvsp[-3].union_string));
            s->value = new V(STRING_ARRAY, (yyvsp[-1].union_expression)->eval_int());
            my_table->insert(*((yyvsp[-3].union_string)),s);
        }
        else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *((yyvsp[-3].union_string)));
        }
    }
    else if((yyvsp[-4].union_int) == T_DOUBLE){
        Symbol *s = my_table->lookup(*((yyvsp[-3].union_string)));
        if(s==NULL){
            Symbol *s = new Symbol;
            s->type = DOUBLE_ARRAY;
            s->name = *((yyvsp[-3].union_string));
            s->value = new V(DOUBLE_ARRAY, (yyvsp[-1].union_expression)->eval_int());
            my_table->insert(*((yyvsp[-3].union_string)),s);
        }
        else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *((yyvsp[-3].union_string)));
        }
    }
}
#line 1752 "y.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 367 "gpl.y" /* yacc.c:1661  */
    {(yyval.union_int) = T_INT;}
#line 1758 "y.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 368 "gpl.y" /* yacc.c:1661  */
    {(yyval.union_int) = T_DOUBLE;}
#line 1764 "y.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 369 "gpl.y" /* yacc.c:1661  */
    {(yyval.union_int) = T_STRING;}
#line 1770 "y.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 375 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_expression) = (yyvsp[0].union_expression);
    }
#line 1778 "y.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 379 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_expression) = NULL;
    }
#line 1786 "y.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 441 "gpl.y" /* yacc.c:1661  */
    { }
#line 1792 "y.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 557 "gpl.y" /* yacc.c:1661  */
    {
        Symbol *s = my_table->lookup(*(yyvsp[0].union_string));
        if(s == NULL){
            Error::error(Error::UNDECLARED_VARIABLE,*(yyvsp[0].union_string));
            (yyval.union_variable) = NULL;
        }
        else{
            (yyval.union_variable) = new Variable(NULL,s);
        }
    }
#line 1807 "y.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 568 "gpl.y" /* yacc.c:1661  */
    {
        if((yyvsp[-1].union_expression)->get_type() == DOUBLE || (yyvsp[-1].union_expression)->get_type() == STRING){
            Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER,*(yyvsp[-3].union_string),"A " + gpl_type_to_string((yyvsp[-1].union_expression)->get_type())+ " expression");
            (yyval.union_variable) = NULL;
        }
        else{
            Symbol *s = my_table->lookup(*(yyvsp[-3].union_string));
            if(s == NULL){
                Error::error(Error::UNDECLARED_VARIABLE, *(yyvsp[-3].union_string));
                (yyval.union_variable) == NULL;
            }
            else{
                if(s->get_type() != STRING_ARRAY && s->get_type() != DOUBLE_ARRAY && s->get_type() != INT_ARRAY){
                    Error::error(Error::VARIABLE_NOT_AN_ARRAY, *(yyvsp[-3].union_string));
                    (yyval.union_variable) = NULL;
                }
                else{
                    if((yyvsp[-1].union_expression)->eval_int() < 0){
                        Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS, *(yyvsp[-3].union_string), (yyvsp[-1].union_expression)->eval_string());
                        (yyval.union_variable) = NULL;   
                    }
                    else{
                        if((yyvsp[-1].union_expression)->eval_int() >= s->get_value()->length){
                            Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS, *(yyvsp[-3].union_string), (yyvsp[-1].union_expression)->eval_string());
                            (yyval.union_variable) = NULL;
                        }
                        else{
                            (yyval.union_variable) = new Variable((yyvsp[-1].union_expression), s);
                        }
                    }
                }
            }
        }
        
    }
#line 1847 "y.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 611 "gpl.y" /* yacc.c:1661  */
    {
        if((yyvsp[-2].union_expression)->get_type() != STRING && (yyvsp[0].union_expression)->get_type() != STRING){
            (yyval.union_expression) = new Expression((yyvsp[-2].union_expression), OR, (yyvsp[0].union_expression));
        }
        else{
            if((yyvsp[-2].union_expression)->get_type() == STRING){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "||");
            }
            if((yyvsp[0].union_expression)->get_type() == STRING){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "||");
            }
            (yyval.union_expression) = new Expression(0);
        }
    }
#line 1866 "y.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 627 "gpl.y" /* yacc.c:1661  */
    {
        if((yyvsp[-2].union_expression)->get_type() != STRING && (yyvsp[0].union_expression)->get_type() != STRING){
            (yyval.union_expression) = new Expression((yyvsp[-2].union_expression), AND, (yyvsp[0].union_expression));
        }
        else{
            if((yyvsp[-2].union_expression)->get_type() == STRING){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "&&");
            }
            if((yyvsp[0].union_expression)->get_type() == STRING){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "&&");
            }
            (yyval.union_expression) = new Expression(0);
        }
    }
#line 1885 "y.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 643 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_expression) = new Expression((yyvsp[-2].union_expression), LESS_THAN_EQUAL, (yyvsp[0].union_expression));
    }
#line 1893 "y.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 648 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_expression) = new Expression((yyvsp[-2].union_expression), GREATER_THAN_EQUAL, (yyvsp[0].union_expression));
    }
#line 1901 "y.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 653 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_expression) = new Expression((yyvsp[-2].union_expression), LESS_THAN, (yyvsp[0].union_expression));
    }
#line 1909 "y.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 658 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_expression) = new Expression((yyvsp[-2].union_expression), GREATER_THAN, (yyvsp[0].union_expression));
    }
#line 1917 "y.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 663 "gpl.y" /* yacc.c:1661  */
    {  
        (yyval.union_expression) = new Expression((yyvsp[-2].union_expression), EQUAL, (yyvsp[0].union_expression));
    }
#line 1925 "y.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 668 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_expression) = new Expression((yyvsp[-2].union_expression), NOT_EQUAL, (yyvsp[0].union_expression));
    }
#line 1933 "y.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 673 "gpl.y" /* yacc.c:1661  */
    {
        //REMIND - Add error check
        (yyval.union_expression) = new Expression((yyvsp[-2].union_expression), PLUS, (yyvsp[0].union_expression));
    }
#line 1942 "y.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 679 "gpl.y" /* yacc.c:1661  */
    {
        if((yyvsp[-2].union_expression)->get_type() != STRING && (yyvsp[0].union_expression)->get_type() != STRING){
            (yyval.union_expression) = new Expression((yyvsp[-2].union_expression), MINUS, (yyvsp[0].union_expression));
        }
        else{
            if((yyvsp[-2].union_expression)->get_type() == STRING){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE,"-");
            }
            if((yyvsp[0].union_expression)->get_type() == STRING){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"-");
            }
            (yyval.union_expression) = new Expression(0);         
        }
    }
#line 1961 "y.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 695 "gpl.y" /* yacc.c:1661  */
    {
        if((yyvsp[-2].union_expression)->get_type() != STRING && (yyvsp[0].union_expression)->get_type() != STRING){
            (yyval.union_expression) = new Expression((yyvsp[-2].union_expression), MULTIPLY, (yyvsp[0].union_expression));
        }
        else{
            if((yyvsp[-2].union_expression)->get_type() == STRING){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE,"*");
            }
            if((yyvsp[0].union_expression)->get_type() == STRING){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"*");  
            }
            (yyval.union_expression) = new Expression(0);
        }
    }
#line 1980 "y.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 711 "gpl.y" /* yacc.c:1661  */
    {
        if((yyvsp[-2].union_expression)->get_type() != STRING && (yyvsp[0].union_expression)->get_type() != STRING){
            if((yyvsp[0].union_expression)->get_type() == DOUBLE && (yyvsp[0].union_expression)->eval_double() != 0){
                (yyval.union_expression) = new Expression((yyvsp[-2].union_expression), DIVIDE, (yyvsp[0].union_expression));
            }
            else if((yyvsp[0].union_expression)->get_type() == INT && (yyvsp[0].union_expression)->eval_int() != 0){
                (yyval.union_expression) = new Expression((yyvsp[-2].union_expression), DIVIDE, (yyvsp[0].union_expression));
            }
            else{
                Error::error(Error::DIVIDE_BY_ZERO_AT_PARSE_TIME);
                (yyval.union_expression) = new Expression(0);
            }
        }
        else{
            if((yyvsp[-2].union_expression)->get_type() == STRING){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "/");
            }
            else if((yyvsp[0].union_expression)->get_type() == STRING){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "/");
            }
            (yyval.union_expression) = new Expression(0);
        }
    }
#line 2008 "y.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 736 "gpl.y" /* yacc.c:1661  */
    {
        if((yyvsp[-2].union_expression)->get_type() == INT && (yyvsp[0].union_expression)->get_type() == INT){
            if((yyvsp[0].union_expression)->eval_int() == 0){
                Error::error(Error::MOD_BY_ZERO_AT_PARSE_TIME);
                (yyval.union_expression) = new Expression(0);
            }
            else{
                (yyval.union_expression) = new Expression((yyvsp[-2].union_expression),MOD,(yyvsp[0].union_expression));
            }
        }
        else{
            if((yyvsp[-2].union_expression)->get_type() != INT){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE, operator_to_string(MOD));         
            }
            if((yyvsp[0].union_expression)->get_type() != INT){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, operator_to_string(MOD));
            }
            (yyval.union_expression) = new Expression(0);
        }
    }
#line 2033 "y.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 758 "gpl.y" /* yacc.c:1661  */
    {
        if((yyvsp[0].union_expression)->get_type() != STRING){
            (yyval.union_expression) = new Expression(UNARY_MINUS, (yyvsp[0].union_expression));
        }
        else{
            (yyval.union_expression) = new Expression(0);
        }
    }
#line 2046 "y.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 767 "gpl.y" /* yacc.c:1661  */
    {
        if((yyvsp[0].union_expression)->get_type() != STRING){
            (yyval.union_expression) = new Expression(NOT, (yyvsp[0].union_expression));
        }
        else{
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "!");
            (yyval.union_expression) = new Expression(0);
        }
    }
#line 2060 "y.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 777 "gpl.y" /* yacc.c:1661  */
    {
        if((yyvsp[-1].union_expression)->get_type() != STRING){
            (yyval.union_expression) = new Expression((yyvsp[-3].union_int),(yyvsp[-1].union_expression));
        }
        else{
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, operator_to_string((Operator_type)(yyvsp[-3].union_int)));
            (yyval.union_expression) = new Expression(0);
        }
    }
#line 2074 "y.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 792 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_expression) = (yyvsp[-1].union_expression);
    }
#line 2082 "y.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 796 "gpl.y" /* yacc.c:1661  */
    {
        if((yyvsp[0].union_variable) != NULL){
            (yyval.union_expression) = new Expression((yyvsp[0].union_variable));
        }
        else{
            (yyval.union_expression) = new Expression(0);
        }
    }
#line 2095 "y.tab.c" /* yacc.c:1661  */
    break;

  case 110:
#line 805 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_expression) = new Expression((yyvsp[0].union_int));
    }
#line 2103 "y.tab.c" /* yacc.c:1661  */
    break;

  case 111:
#line 809 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_expression) = new Expression(1);
    }
#line 2111 "y.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 813 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_expression) = new Expression(0);
    }
#line 2119 "y.tab.c" /* yacc.c:1661  */
    break;

  case 113:
#line 817 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_expression) = new Expression((yyvsp[0].union_double));
    }
#line 2127 "y.tab.c" /* yacc.c:1661  */
    break;

  case 114:
#line 821 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_expression) = new Expression(*(yyvsp[0].union_string));
    }
#line 2135 "y.tab.c" /* yacc.c:1661  */
    break;

  case 117:
#line 835 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_int) = SIN;
    }
#line 2143 "y.tab.c" /* yacc.c:1661  */
    break;

  case 118:
#line 840 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_int) = COS;
    }
#line 2151 "y.tab.c" /* yacc.c:1661  */
    break;

  case 119:
#line 845 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_int) = TAN;
    }
#line 2159 "y.tab.c" /* yacc.c:1661  */
    break;

  case 120:
#line 850 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_int) = ASIN;
    }
#line 2167 "y.tab.c" /* yacc.c:1661  */
    break;

  case 121:
#line 855 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_int) = ACOS;
    }
#line 2175 "y.tab.c" /* yacc.c:1661  */
    break;

  case 122:
#line 860 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_int) = ATAN;
    }
#line 2183 "y.tab.c" /* yacc.c:1661  */
    break;

  case 123:
#line 865 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_int) = SQRT;
    }
#line 2191 "y.tab.c" /* yacc.c:1661  */
    break;

  case 124:
#line 870 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_int) = ABS;
    }
#line 2199 "y.tab.c" /* yacc.c:1661  */
    break;

  case 125:
#line 875 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_int) = FLOOR;
    }
#line 2207 "y.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 880 "gpl.y" /* yacc.c:1661  */
    {
        (yyval.union_int) = RANDOM;
    }
#line 2215 "y.tab.c" /* yacc.c:1661  */
    break;


#line 2219 "y.tab.c" /* yacc.c:1661  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
