/*

  This file contains the input to the bison compiler generator.
  bison will use this file to generate a C/C++ parser.

  The default output file for bison is: y.tab.c

    $ bison record.y    will produce the file y.tab.c

  This grammar describes a language that is a collection of record
  declarations.  Each has a name and zero or more fields.

    record sally
    {
      height = 63;
      weight = 132;
      age = 42;
    }

    record george
    {
      age = 31;
      phone = 5551212;
    }

  This example DOES NOT demonstrate how a real language would
  create records.  It is a contrived and overly simplified 
  example to demonstrate the bison/flex syntax.
  
*/


%{  // bison syntax to indicate the start of the header
    // the header is copied directly into y.tab.c (the generated parser)

#include "symbol_table.h"

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
%} 

// The union is used to declare the variable yylval which is used to
// pass data between the flex generated lexer and the bison generated parser, 
// and to pass values up/down the parse tree.
// 
// A union is kind of like a structure or class, but you can only use one 
// field at a time.  Each line describes one item in the union.  The left hand
// side is the type, the right hand side is a name for the type.
// 
// Unions do not have any error checking.  For example, if you put an int in
// the following union  (my_union.union_int = 42)  and then attempt to use it
// as a string (cout << my_union.union_string) you will get garbage.

// The "%union" is bison syntax
// The "union_" is my convention to indicate a member of the union 
//     (it can be hard to tell what is a union field and what is not)
//
// In this example, the union only has one member (union_int).  You will
// be adding a double declaration to the union.

%union {
 int            union_int;
 double         union_double;
 std::string    *union_string;  // MUST be a pointer to a string (this sucks!)
}

// Tokens with a < > after the %token require a type.
// This is the type of the variable the scanner puts into the union.
// Fill in the < > with the appropriate type
//     for example
//     %token <union_int> T_INT_CONSTANT       "int constant"

%error-verbose

%token T_INT                 "int"
%token T_DOUBLE              "double"
%token T_STRING              "string"
%token T_TRIANGLE            "triangle"
%token T_PIXMAP              "pixmap"
%token T_CIRCLE              "circle"
%token T_RECTANGLE           "rectangle"
%token T_TEXTBOX             "textbox"
%token <union_int> T_FORWARD "forward" // value is line number
%token T_INITIALIZATION      "initialization"

%token T_TRUE                "true"
%token T_FALSE               "false"

%token T_TOUCHES             "touches"
%token T_NEAR                "near"

%token T_ANIMATION           "animation"

%token T_IF                  "if"
%token T_FOR                 "for"
%nonassoc IF_NO_ELSE
%nonassoc T_ELSE             "else"
%token <union_int> T_PRINT   "print" // value is line number
%token <union_int> T_EXIT    "exit" // value is line number

%token T_LPAREN              "("
%token T_RPAREN              ")"
%token T_LBRACE              "{"
%token T_RBRACE              "}"
%token T_LBRACKET            "["
%token T_RBRACKET            "]"
%token T_SEMIC               ";"
%token T_COMMA               ","
%token T_PERIOD              "."

%token T_ASSIGN              "="
%token T_PLUS_ASSIGN         "+="
%token T_MINUS_ASSIGN        "-="






%token T_SIN                 "sin"
%token T_COS                 "cos"
%token T_TAN                 "tan"
%token T_ASIN                "asin"
%token T_ACOS                "acos"
%token T_ATAN                "atan"
%token T_SQRT                "sqrt"
%token T_FLOOR               "floor"
%token T_ABS                 "abs"
%token T_RANDOM              "random"

%token T_NOT                "!"
%left T_NOT                 
%token T_OR                 "||"
%left T_OR                  
%token T_AND                "&&"
%left T_AND                 

%token T_NOT_EQUAL          "!="
%left T_NOT_EQUAL      
%token T_EQUAL              "=="
%left T_EQUAL
%token T_GREATER_EQUAL      ">="         
%left T_GREATER_EQUAL   
%token T_LESS_EQUAL         "<="    
%left T_LESS_EQUAL
%token T_GREATER            ">"
%left T_GREATER    
%token T_LESS               "<"
%left T_LESS                

%token T_MINUS              "-"      
%left T_MINUS               
%token T_PLUS               "+"
%left T_PLUS     
%token T_MOD                 "%"            
%left T_MOD                  
%token T_DIVIDE              "/"
%left T_DIVIDE  
%token T_ASTERISK            "*"             
%left T_ASTERISK           

%token T_ON                  "on"
%token T_SPACE               "space"
%token T_LEFTARROW           "leftarrow"
%token T_RIGHTARROW          "rightarrow"
%token T_UPARROW             "uparrow"
%token T_DOWNARROW           "downarrow"
%token T_LEFTMOUSE_DOWN      "leftmouse_down"
%token T_MIDDLEMOUSE_DOWN    "middlemouse_down"
%token T_RIGHTMOUSE_DOWN     "rightmouse_down"
%token T_LEFTMOUSE_UP        "leftmouse_up"
%token T_MIDDLEMOUSE_UP      "middlemouse_up"
%token T_RIGHTMOUSE_UP       "rightmouse_up"
%token T_MOUSE_MOVE          "mouse_move"
%token T_MOUSE_DRAG          "mouse_drag"
%token T_F1                  "f1"
%token T_AKEY                "akey"
%token T_SKEY                "skey"
%token T_DKEY                "dkey"
%token T_FKEY                "fkey"
%token T_HKEY                "hkey"
%token T_JKEY                "jkey"
%token T_KKEY                "kkey"
%token T_LKEY                "lkey"
%token T_WKEY                "wkey"

%token <union_string> T_ID              "identifier"
%token <union_int> T_INT_CONSTANT    "int constant"
%token <union_double> T_DOUBLE_CONSTANT "double constant"
%token <union_string> T_STRING_CONSTANT "string constant"

// special token that does not match any production
// used for characters that are not part of the language
%token T_ERROR               "error"

%type <union_int> simple_type

%nonassoc UNARY_OPS

%% // indicates the start of the rules

//---------------------------------------------------------------------
program:
    declaration_list block_list
    ;

//---------------------------------------------------------------------
declaration_list:
    declaration_list declaration
    | empty
    ;

//---------------------------------------------------------------------
declaration:
    variable_declaration T_SEMIC
    | object_declaration T_SEMIC
    | forward_declaration T_SEMIC
    ;

//---------------------------------------------------------------------
variable_declaration:
simple_type  T_ID  optional_initializer {
    if($1 == T_INT){
        Symbol *s = my_table->lookup(*($2));
        if(s==NULL){
            Symbol *s = new Symbol;
            s->type = INT;
            s->name = *($2);
            s->value = new V(42);
            my_table->insert(*$2,s);
        }
        else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *($2));
        }
    }
    else if($1 == T_STRING){
        Symbol *s = my_table->lookup(*($2));
        if(s==NULL){
            Symbol *s = new Symbol;
            s->type = STRING;
            s->name = *($2);
            s->value = new V("Hello world");
            my_table->insert(*$2,s);
        }
        else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *($2));
        }
    }
    else if($1 == T_DOUBLE){
        Symbol *s = my_table->lookup(*($2));
        if(s==NULL){
            Symbol *s = new Symbol;
            s->type = DOUBLE;
            s->name = *($2);
            s->value = new V(3.14159);
            my_table->insert(*$2,s);
        }
        else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *($2));
        }
    }
}
    //| simple_type  T_ID  T_LBRACKET expression T_RBRACKET}

|simple_type T_ID T_LBRACKET T_INT_CONSTANT T_RBRACKET {
    if($1 == T_INT){
        Symbol *s = my_table->lookup(*($2));
        if(s==NULL){
            Symbol *s = new Symbol;
            s->type = INT_ARRAY;
            s->name = *($2);
            s->value = new V(INT_ARRAY, $4);     
            my_table->insert(*($2),s);
        }
        else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *($2));
        }
    }
    else if($1 == T_STRING){
        Symbol *s = my_table->lookup(*($2));
        if(s==NULL){
            Symbol *s = new Symbol;
            s->type = STRING_ARRAY;
            s->name = *($2);
            s->value = new V(STRING_ARRAY, $4);
            my_table->insert(*($2),s);
        }
        else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *($2));
        }
    }
    else if($1 == T_DOUBLE){
        Symbol *s = my_table->lookup(*($2));
        if(s==NULL){
            Symbol *s = new Symbol;
            s->type = DOUBLE_ARRAY;
            s->name = *($2);
            s->value = new V(DOUBLE_ARRAY, $4);
            my_table->insert(*($2),s);
        }
        else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *($2));
        }
    }
}
    ;

//---------------------------------------------------------------------
simple_type:
    T_INT {$$ = T_INT;}
    | T_DOUBLE {$$ = T_DOUBLE;}
    | T_STRING {$$ = T_STRING;}
    ;

//---------------------------------------------------------------------
optional_initializer:
    T_ASSIGN expression
    | empty
    ;

//---------------------------------------------------------------------
object_declaration:
    object_type T_ID T_LPAREN parameter_list_or_empty T_RPAREN
    | object_type T_ID T_LBRACKET expression T_RBRACKET
    ;

//---------------------------------------------------------------------
object_type:
    T_TRIANGLE
    | T_PIXMAP
    | T_CIRCLE
    | T_RECTANGLE
    | T_TEXTBOX
    ;

//---------------------------------------------------------------------
parameter_list_or_empty :
    parameter_list
    | empty
    ;

//---------------------------------------------------------------------
parameter_list :
    parameter_list T_COMMA parameter
    | parameter
    ;

//---------------------------------------------------------------------
parameter:
    T_ID T_ASSIGN expression
    ;

//---------------------------------------------------------------------
forward_declaration:
    T_FORWARD T_ANIMATION T_ID T_LPAREN animation_parameter T_RPAREN
    ;

//---------------------------------------------------------------------
block_list:
    block_list block
    | empty
    ;

//---------------------------------------------------------------------
block:
    initialization_block
    | animation_block
    | on_block
    ;

//---------------------------------------------------------------------
initialization_block:
    T_INITIALIZATION statement_block
    ;

//---------------------------------------------------------------------
animation_block:
    T_ANIMATION T_ID T_LPAREN check_animation_parameter T_RPAREN T_LBRACE { } statement_list T_RBRACE end_of_statement_block
    ;

//---------------------------------------------------------------------
animation_parameter:
    object_type T_ID
    ;

//---------------------------------------------------------------------
check_animation_parameter:
    T_TRIANGLE T_ID
    | T_PIXMAP T_ID
    | T_CIRCLE T_ID
    | T_RECTANGLE T_ID
    | T_TEXTBOX T_ID
    ;

//---------------------------------------------------------------------
on_block:
    T_ON keystroke statement_block
    ;

//---------------------------------------------------------------------
keystroke:
    T_SPACE
    | T_UPARROW
    | T_DOWNARROW
    | T_LEFTARROW
    | T_RIGHTARROW
    | T_LEFTMOUSE_DOWN
    | T_MIDDLEMOUSE_DOWN
    | T_RIGHTMOUSE_DOWN
    | T_LEFTMOUSE_UP
    | T_MIDDLEMOUSE_UP
    | T_RIGHTMOUSE_UP
    | T_MOUSE_MOVE
    | T_MOUSE_DRAG
    | T_AKEY 
    | T_SKEY 
    | T_DKEY 
    | T_FKEY 
    | T_HKEY 
    | T_JKEY 
    | T_KKEY 
    | T_LKEY 
    | T_WKEY 
    | T_F1
    ;

//---------------------------------------------------------------------
if_block:
    statement_block_creator statement end_of_statement_block
    | statement_block
    ;

//---------------------------------------------------------------------
statement_block:
    T_LBRACE statement_block_creator statement_list T_RBRACE end_of_statement_block
    ;

//---------------------------------------------------------------------
statement_block_creator:
    // this goes to nothing so that you can put an action here in p7
    ;

//---------------------------------------------------------------------
end_of_statement_block:
    // this goes to nothing so that you can put an action here in p7
    ;

//---------------------------------------------------------------------
statement_list:
    statement_list statement
    | empty
    ;

//---------------------------------------------------------------------
statement:
    if_statement
    | for_statement
    | assign_statement T_SEMIC
    | print_statement T_SEMIC
    | exit_statement T_SEMIC
    ;

//---------------------------------------------------------------------
if_statement:
    T_IF T_LPAREN expression T_RPAREN if_block %prec IF_NO_ELSE
    | T_IF T_LPAREN expression T_RPAREN if_block T_ELSE if_block 
    ;

//---------------------------------------------------------------------
for_statement:
    T_FOR T_LPAREN statement_block_creator assign_statement end_of_statement_block T_SEMIC expression T_SEMIC statement_block_creator assign_statement end_of_statement_block T_RPAREN statement_block
    ;

//---------------------------------------------------------------------
print_statement:
    T_PRINT T_LPAREN expression T_RPAREN
    ;

//---------------------------------------------------------------------
exit_statement:
    T_EXIT T_LPAREN expression T_RPAREN
    ;

//---------------------------------------------------------------------
assign_statement:
    variable T_ASSIGN expression
    | variable T_PLUS_ASSIGN expression
    | variable T_MINUS_ASSIGN expression
    ;

//---------------------------------------------------------------------
variable:
    T_ID
    | T_ID T_LBRACKET expression T_RBRACKET
    | T_ID T_PERIOD T_ID
    | T_ID T_LBRACKET expression T_RBRACKET T_PERIOD T_ID
    ;

//---------------------------------------------------------------------
expression:
    primary_expression
    | expression T_OR expression
    | expression T_AND expression
    | expression T_LESS_EQUAL expression
    | expression T_GREATER_EQUAL  expression
    | expression T_LESS expression 
    | expression T_GREATER  expression
    | expression T_EQUAL expression
    | expression T_NOT_EQUAL expression
    | expression T_PLUS expression 
    | expression T_MINUS expression
    | expression T_ASTERISK expression
    | expression T_DIVIDE expression
    | expression T_MOD expression
    | T_MINUS expression %prec UNARY_OPS
    | T_NOT expression %prec UNARY_OPS
    | math_operator T_LPAREN expression T_RPAREN
    | variable geometric_operator variable
    ;

//---------------------------------------------------------------------
primary_expression:
    T_LPAREN  expression T_RPAREN
    | variable
    | T_INT_CONSTANT
    | T_TRUE
    | T_FALSE
    | T_DOUBLE_CONSTANT
    | T_STRING_CONSTANT
    ;

//---------------------------------------------------------------------
geometric_operator:
    T_TOUCHES
    | T_NEAR
    ;

//---------------------------------------------------------------------
math_operator:
    T_SIN
    | T_COS
    | T_TAN
    | T_ASIN
    | T_ACOS
    | T_ATAN
    | T_SQRT
    | T_ABS
    | T_FLOOR
    | T_RANDOM
    ;

//---------------------------------------------------------------------
empty:
    // empty goes to nothing so that you can use empty in productions
    // when you want a production to go to nothing
    ;

