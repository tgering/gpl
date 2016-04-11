/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 73 "gpl.y" /* yacc.c:1915  */

  #include "expression.h" 
  #include "variable.h" 
  #include <sstream>

#line 50 "y.tab.h" /* yacc.c:1915  */

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
#line 80 "gpl.y" /* yacc.c:1915  */

 int            union_int;
 double         union_double;
 std::string    *union_string;  // MUST be a pointer to a string (this sucks!)
 Expression     *union_expression;
 Variable       *union_variable;

#line 248 "y.tab.h" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
