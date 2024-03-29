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
#include "expression.h"
#include "event_manager.h"

Symbol_table *my_table = Symbol_table::instance();
extern int yylex();               // this lexer function returns next token
extern int yyerror(const char *); // used to print errors
extern int line_count;            // current line in the input; from record.l

#include "error.h"      // class for printing errors (used by gpl)
#include "parser.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;


Game_object *cur_object_under_construction;
string cur_object_name;
stack<Statement_block*> my_block_stack;
Event_manager *my_event_manager = Event_manager::instance();
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

%code requires 
{
  #include "for_statement.h"
  #include "assign_statement.h"
  #include "if_statement.h"
  #include "print_statement.h"
  #include "exit_statement.h"
  #include "expression.h" 
  #include "variable.h" 
  #include "game_object.h"
  #include "triangle.h"
  #include "rectangle.h"
  #include "circle.h"
  #include "textbox.h"
  #include "pixmap.h"
  #include "animation_block.h"
  #include <sstream>
}

%union 
{
 int            union_int;
 double         union_double;
 std::string    *union_string;  // MUST be a pointer to a string (this sucks!)
 Expression     *union_expression;
 Variable       *union_variable;
 Symbol         *union_symbol;
 Statement_block *union_statement_block;
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
%token T_EQUAL              "=="
%left T_EQUAL T_NOT_EQUAL

%token T_GREATER_EQUAL      ">="           
%token T_LESS_EQUAL         "<="    
%token T_GREATER            ">"
%token T_LESS               "<"
%left T_LESS T_GREATER_EQUAL T_GREATER  T_LESS_EQUAL              

%token T_MINUS              "-"      
%token T_PLUS               "+"
%left T_PLUS T_MINUS    

%token T_MOD                 "%"                     
%token T_DIVIDE              "/"
%token T_ASTERISK            "*"             
%left T_ASTERISK T_MOD T_DIVIDE       

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

%type <union_int> object_type
%type <union_int> simple_type
%type <union_expression> expression
%type <union_expression> optional_initializer
%type <union_expression> primary_expression
%type <union_int> math_operator
%type <union_int> geometric_operator
%type <union_variable> variable 
%type <union_symbol> animation_parameter
%type <union_symbol> check_animation_parameter
%type <union_statement_block> end_of_statement_block
%type <union_statement_block> statement_block
%type <union_statement_block> if_block
%type <union_int> keystroke
%type <union_statement_block> assign_statement
%type <union_statement_block> print_statement

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
        int initial_value = 0;
        if($3 != NULL){
            if($3->get_type() != INT){
                if($3->get_type() == DOUBLE){
                    Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE, "double", *$2, "int");
                }
                else if($3->get_type() == STRING){
                    Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE, "string", *$2, "int");
                }
            }
            else{
                initial_value = $3->eval_int();
            }
        }

        //Insert symbol into the table
        Symbol *s = my_table->lookup(*($2));
        if(s==NULL){
            Symbol *s = new Symbol();
            s->type = INT;
            s->name = *($2);
            s->value = new V(initial_value);
            my_table->insert(*$2,s);
        }
        else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *($2));
        }
    }
    else if($1 == T_STRING){
        string initial_value = "";
        if($3 != NULL){
            initial_value = $3->eval_string();   
        }

        Symbol *s = my_table->lookup(*($2));
        if(s==NULL){
            Symbol *s = new Symbol();
            s->type = STRING;
            s->name = *($2);
            s->value = new V(initial_value);
            my_table->insert(*$2,s);
        }
        else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *($2));
        }
    }
    else if($1 == T_DOUBLE){
        double initial_value = 0.0;
        if($3 != NULL){
            if($3->get_type() == STRING){
                Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE,"string",*$2,"double");
            }
            else{
                initial_value = $3->eval_double();
            }
        }


        Symbol *s = my_table->lookup(*($2));
        if(s==NULL){
            Symbol *s = new Symbol();
            s->type = DOUBLE;
            s->name = *($2);
            s->value = new V(initial_value);
            my_table->insert(*$2,s);
        }
        else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *($2));
        }
    }
}
| simple_type  T_ID  T_LBRACKET expression T_RBRACKET{
    if($4->get_type() != INT){
        Error::error(Error::INVALID_ARRAY_SIZE, *$2, $4->eval_string());
    }
    else if($4->eval_int() <= 0){
        Error::error(Error::INVALID_ARRAY_SIZE, *$2, $4->eval_string());     
    }
    else if($1 == T_INT){
        Symbol *s = my_table->lookup(*($2));
        if(s==NULL){
            Symbol *s = new Symbol();
            s->type = INT_ARRAY;
            s->name = *($2);
            s->value = new V(INT_ARRAY, $4->eval_int());     
            my_table->insert(*($2),s);
        }
        else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *($2));
        }
    }
    else if($1 == T_STRING){
        Symbol *s = my_table->lookup(*($2));
        if(s==NULL){
            Symbol *s = new Symbol();
            s->type = STRING_ARRAY;
            s->name = *($2);
            s->value = new V(STRING_ARRAY, $4->eval_int());
            my_table->insert(*($2),s);
        }
        else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *($2));
        }
    }
    else if($1 == T_DOUBLE){
        Symbol *s = my_table->lookup(*($2));
        if(s==NULL){
            Symbol *s = new Symbol();
            s->type = DOUBLE_ARRAY;
            s->name = *($2);
            s->value = new V(DOUBLE_ARRAY, $4->eval_int());
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
    {
        $$ = $2;
    }
    | empty
    {
        $$ = NULL;
    }
    ;

//---------------------------------------------------------------------
object_declaration:
    object_type T_ID {
        switch($1){
            case TRIANGLE:
                cur_object_under_construction = new Triangle();
                cur_object_name = *($2);
                break;
            case PIXMAP:
                cur_object_under_construction = new Pixmap();
                cur_object_name = *($2);
                break;
            case CIRCLE:
                cur_object_under_construction = new Circle();
                cur_object_name = *($2);
                break;
            case RECTANGLE:
                cur_object_under_construction = new Rectangle();
                cur_object_name = *($2);
                break;
            case TEXTBOX:
                cur_object_under_construction = new Textbox();
                cur_object_name = *($2);
                break;
            default:
                break;
        }
    } 
    T_LPAREN parameter_list_or_empty T_RPAREN
    {
        Symbol *s = my_table->lookup(*($2));
        if(s==NULL){
            s = new Symbol(cur_object_under_construction);
            s->type = GAME_OBJECT;
            s->name = *($2);
            my_table->insert(*($2),s);
        }
        else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *($2));
        }
    }
    | object_type T_ID T_LBRACKET expression T_RBRACKET
    { 
       Symbol *s = my_table->lookup(*($2));
        if(s==NULL){
            s = new Symbol();
            s->type = GAME_OBJECT_ARRAY;
            s->name = *($2);
            //cout<< "Calling constructor " << endl;
            s->value = new V(Gpl_type($1), int($4->eval_int()));
            my_table->insert(*($2),s);
       }
       else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *($2));
       }
    }
    ;

//---------------------------------------------------------------------
object_type:
    T_TRIANGLE{$$ = TRIANGLE;}
    | T_PIXMAP{$$ = PIXMAP;}
    | T_CIRCLE{$$ = CIRCLE;}
    | T_RECTANGLE{$$ = RECTANGLE;}
    | T_TEXTBOX{$$ = TEXTBOX;}
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
    {
        Status status = OK;
        Gpl_type t = $3->get_type();
        if(t == STRING){
            status = cur_object_under_construction->set_member_variable(*($1), $3->eval_string());
        }
        else if(t == INT){
            Gpl_type type;
            Status stat = cur_object_under_construction->get_member_variable_type(*$1,type);

            if(type == DOUBLE){
                status = cur_object_under_construction->set_member_variable(*($1), $3->eval_double());
            }
            else if(type == INT){
               status = cur_object_under_construction->set_member_variable(*($1), $3->eval_int()); 
            }
            else if(type == STRING){
                status = cur_object_under_construction->set_member_variable(*($1), $3->eval_string());
            }

            if(stat == MEMBER_NOT_OF_GIVEN_TYPE){
                Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, cur_object_name, *$1);
            }
            else if(stat == MEMBER_NOT_DECLARED){
                Error::error(Error::UNKNOWN_CONSTRUCTOR_PARAMETER, cur_object_under_construction->type(), *$1);
            }
            
        }
        else if(t == DOUBLE){
            Gpl_type type;
            Status stat = cur_object_under_construction->get_member_variable_type(*$1,type);
            if(type == STRING){
               status = cur_object_under_construction->set_member_variable(*($1), $3->eval_string()); 
            }
            else{
                status = cur_object_under_construction->set_member_variable(*($1), $3->eval_double());
            }
            if(stat == MEMBER_NOT_OF_GIVEN_TYPE){
                Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, cur_object_name, *$1);
            }
            else if(stat == MEMBER_NOT_DECLARED){
                Error::error(Error::UNKNOWN_CONSTRUCTOR_PARAMETER, cur_object_under_construction->type(), *$1);
            }
        }
        else if(t == ANIMATION_BLOCK){
            Animation_block *a = $3->eval_animation_block();
            Symbol *s = a->get_parameter_symbol();
            Game_object *g = s->get_game_object_value();
            if(g->type() == cur_object_under_construction->type()){
                status = cur_object_under_construction->set_member_variable(*($1), $3->eval_animation_block());
            }
            else{
                Error::error(Error::TYPE_MISMATCH_BETWEEN_ANIMATION_BLOCK_AND_OBJECT,cur_object_name,a->name());
            }
        }
        if(status == MEMBER_NOT_OF_GIVEN_TYPE){
            Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, cur_object_name, *$1);
        }
        else if(status == MEMBER_NOT_DECLARED){
            Error::error(Error::UNKNOWN_CONSTRUCTOR_PARAMETER, cur_object_under_construction->type(), *$1);
        }
        
    }
    ;

//---------------------------------------------------------------------
forward_declaration:
    T_FORWARD T_ANIMATION T_ID T_LPAREN animation_parameter T_RPAREN
    {
       Symbol *s = my_table->lookup(*($3));
       if(s== NULL){
            Animation_block *block = new Animation_block;
            s = new Symbol(block);
            s->type = ANIMATION_BLOCK;
            s->name = *($3);
            block->initialize($5,*($3));
            my_table->insert(*($3),s);
       }
       else{
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE,*($3));
       }
    }
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
    {
        my_event_manager->add_statement_block($2,Window::INITIALIZE);
    }
    ;

//---------------------------------------------------------------------
animation_block:
    T_ANIMATION T_ID T_LPAREN check_animation_parameter 
    { 
        Symbol *s = my_table->lookup(*$2);
        if(s != NULL){
            Animation_block *a = s->get_animation_block_value();
            if(a->get_parameter_symbol()->get_name() != $4->get_name()){
                Error::error(Error::ANIMATION_PARAM_DOES_NOT_MATCH_FORWARD);
            }
            my_block_stack.push(a);
        }
        else{
            Error::error(Error::NO_FORWARD_FOR_ANIMATION_BLOCK,*$2);
            my_block_stack.push(NULL);
        } 
    } 
    T_RPAREN T_LBRACE statement_list T_RBRACE end_of_statement_block
    {
    }
    ;

//---------------------------------------------------------------------
animation_parameter:
    object_type T_ID
    {
        Symbol *s;
        Rectangle *r;
        Textbox *t;
        Triangle *tr;
        Pixmap *p;
        Circle *c;
        Symbol *duplicate = my_table->lookup(*$2);
        if(duplicate == NULL){
            switch($1){
                case TRIANGLE:
                    tr = new Triangle();
                    tr->never_animate();
                    tr->never_draw();
                    s = new Symbol(tr);
                    s->name = *($2);
                    s->type = GAME_OBJECT;
                    my_table->insert(*($2), s);
                    $$ = s;
                    break;

                case RECTANGLE:
                    r = new Rectangle();
                    r->never_animate();
                    r->never_draw();
                    s = new Symbol(r);
                    s->type = GAME_OBJECT;
                    s->name = *($2);
                    my_table->insert(*($2), s);
                    $$ = s;
                    break;

                case PIXMAP:
                    p = new Pixmap();
                    p->never_animate();
                    p->never_draw();
                    s = new Symbol(p);
                    s->type = GAME_OBJECT;
                    s->name = *($2);
                    my_table->insert(*($2), s);
                    $$ = s;
                    break;

                case CIRCLE:
                    c = new Circle();
                    c->never_animate();
                    c->never_draw();
                    s = new Symbol(c);
                    s->type = GAME_OBJECT;
                    s->name = *($2);
                    my_table->insert(*($2), s);
                    $$ = s;
                    break;

                case TEXTBOX:
                    t = new Textbox();
                    t->never_animate();
                    t->never_draw();
                    s = new Symbol(t);
                    s->type = GAME_OBJECT;
                    s->name = *($2);
                    my_table->insert(*($2), s);
                    $$ = s;
                    break;
            }
        }
        else{
            Error::error(Error::ANIMATION_PARAMETER_NAME_NOT_UNIQUE, *$2);
            $$ = NULL;
        }
    }
    ;

//---------------------------------------------------------------------
check_animation_parameter:
    T_TRIANGLE T_ID
    {
        Triangle *t = new Triangle();
        t->never_animate();
        t->never_draw();
        Symbol *s = new Symbol(t);
        s->name = *($2);
        s->type = GAME_OBJECT;
        my_table->insert(*($2), s);
        $$ = s;
    }
    | T_PIXMAP T_ID
    {
        Pixmap *p = new Pixmap();
        p->never_animate();
        p->never_draw();
        Symbol *s = new Symbol(p);
        s->type = GAME_OBJECT;
        s->name = *($2);
        my_table->insert(*($2), s);
        $$ = s;
    }
    | T_CIRCLE T_ID
    {
        Circle *c = new Circle();
        c->never_animate();
        c->never_draw();
        Symbol *s = new Symbol(c);
        s->type = GAME_OBJECT;
        s->name = *($2);
        my_table->insert(*($2), s);
        $$ = s;
    }
    | T_RECTANGLE T_ID
    {
        Rectangle *r = new Rectangle();
        r->never_animate();
        r->never_draw();
        Symbol *s = new Symbol(r);
        s->type = GAME_OBJECT;
        s->name = *($2);
        my_table->insert(*($2), s);
        $$ = s;
    }
    | T_TEXTBOX T_ID
    {
        Textbox *t = new Textbox();
        t->never_animate();
        t->never_draw();
        Symbol *s = new Symbol(t);
        s->type = GAME_OBJECT;
        s->name = *($2);
        my_table->insert(*($2), s);
        $$ = s;
    }
    ;

//---------------------------------------------------------------------
on_block:
    T_ON keystroke statement_block
    {
        my_event_manager->add_statement_block($3,(Window::Keystroke)$2);
    }
    ;

//---------------------------------------------------------------------
keystroke:
    T_SPACE
    {
        $$ = Window::SPACE;
    }
    | T_UPARROW{
        $$ = Window::UPARROW;
    }
    | T_DOWNARROW
    {
        $$ = Window::DOWNARROW;
    }
    | T_LEFTARROW
    {
        $$ = Window::LEFTARROW;
    }
    | T_RIGHTARROW
    {
        $$ = Window::RIGHTARROW;
    }
    | T_LEFTMOUSE_DOWN
    {
        $$ = Window::LEFTMOUSE_DOWN;
    }
    | T_MIDDLEMOUSE_DOWN
    {
        $$ = Window::MIDDLEMOUSE_DOWN;
    }
    | T_RIGHTMOUSE_DOWN
    {
        $$ = Window::RIGHTMOUSE_DOWN;
    }
    | T_LEFTMOUSE_UP
    {
        $$ = Window::LEFTMOUSE_UP;
    }
    | T_MIDDLEMOUSE_UP
    {
        $$ = Window::MIDDLEMOUSE_UP;
    }
    | T_RIGHTMOUSE_UP
    {
        $$ = Window::RIGHTMOUSE_UP;
    }
    | T_MOUSE_MOVE
    {
        $$ = Window::MOUSE_MOVE;
    }
    | T_MOUSE_DRAG
    {
        $$ = Window::MOUSE_DRAG;
    }
    | T_AKEY 
    {
        $$ = Window::AKEY;
    }
    | T_SKEY 
    {
        $$ = Window::SKEY;
    }
    | T_DKEY 
    {
        $$ = Window::DKEY;
    }
    | T_FKEY 
    {
        $$ = Window::FKEY;
    }
    | T_HKEY 
    {
        $$ = Window::HKEY;
    }
    | T_JKEY 
    {
        $$ = Window::JKEY;
    }
    | T_KKEY
    {
        $$ = Window::KKEY;
    } 
    | T_LKEY 
    {
        $$ = Window::LKEY;
    }
    | T_WKEY
    {
        $$ = Window::WKEY;
    } 
    | T_F1
    {
        $$ = Window::F1;
    }
    ;

//---------------------------------------------------------------------
if_block:
    statement_block_creator statement end_of_statement_block
    {
        $$ = $3;
    }
    | statement_block
    {
        $$ = $1;
    }

    ;

//---------------------------------------------------------------------
statement_block:
    T_LBRACE statement_block_creator statement_list T_RBRACE end_of_statement_block
    {
        $$ = $5;
    }
    ;

//---------------------------------------------------------------------
statement_block_creator:
{
    Statement_block *s = new Statement_block();
    my_block_stack.push(s);
}
    // this goes to nothing so that you can put an action here in p7
    ;

//---------------------------------------------------------------------
end_of_statement_block:
{
    Statement_block *s = my_block_stack.top();
    my_block_stack.pop();
    $$ = s;
}
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
    {
        if($3!=NULL){
            if($3->get_type() != INT){
                Error::error(Error::INVALID_TYPE_FOR_IF_STMT_EXPRESSION);
            }
            else{
                Statement *s = new If_statement($5,NULL,$3);
                my_block_stack.top()->push_statement(s);
            }
        }
    }
    | T_IF T_LPAREN expression T_RPAREN if_block T_ELSE if_block
    {
        if($3!=NULL){
            if($3->get_type() != INT){
                Error::error(Error::INVALID_TYPE_FOR_IF_STMT_EXPRESSION);
            }
            else{
                Statement *s = new If_statement($5,$7,$3);
                my_block_stack.top()->push_statement(s);
            }
        }
    }
    ;

//---------------------------------------------------------------------
for_statement:
    T_FOR T_LPAREN statement_block_creator assign_statement end_of_statement_block T_SEMIC expression T_SEMIC statement_block_creator assign_statement end_of_statement_block T_RPAREN statement_block
    {
        if($7->get_type() !=INT){
            Error::error(Error::INVALID_TYPE_FOR_FOR_STMT_EXPRESSION);
        }
        else{
            Statement *s = new For_statement($5,$11,$13,$7);
            my_block_stack.top()->push_statement(s);
        }
    }
    ;

//---------------------------------------------------------------------
print_statement:
    T_PRINT T_LPAREN expression T_RPAREN
    {
        if($3 == NULL){
            $$ = NULL;
        }
        else{
            Gpl_type t = $3->get_type();
            if(t != INT && t != DOUBLE && t != STRING){
                Error::error(Error::INVALID_TYPE_FOR_PRINT_STMT_EXPRESSION);
            }
            else{
                Statement *s = new Print_Statement((Expression*)$3,$1);
                my_block_stack.top()->push_statement(s);
            }
        }
    }
    ;

//---------------------------------------------------------------------
exit_statement:
    T_EXIT T_LPAREN expression T_RPAREN
    {
        if($3->get_type() != INT){
            Error::error(Error::EXIT_STATUS_MUST_BE_AN_INTEGER, gpl_type_to_string($3->get_type()));
        }
        else{
            Statement *s = new Exit_statement((Expression*)$3, $1);
            my_block_stack.top()->push_statement(s);
        }
    }
    ;

//---------------------------------------------------------------------
assign_statement:
        variable T_ASSIGN expression 
        {
            if ($1 == NULL || $3 == NULL) {
                $$ = NULL;
            }  
            else{
                Gpl_type et = $3->get_type();
                Gpl_type vt = $1->get_type();
                if (((vt == INT || vt == INT_ARRAY) && et == INT)
                    || ((vt == DOUBLE || vt == DOUBLE_ARRAY) && (et ==INT || et == DOUBLE))
                    || (vt == STRING || vt == STRING_ARRAY) && (et == INT || et == DOUBLE || et == STRING )) {
                    Statement *s = new Assign_statement((Variable *) $1, (Expression *) $3, Assign_statement::EQUAL);
                    my_block_stack.top()->push_statement(s);
                    $$ = my_block_stack.top();
                } 
                else if(vt == ANIMATION_BLOCK && et == ANIMATION_BLOCK){
                    Game_object *g = $1->get_game_object_value();
                    Animation_block *a = $3->eval_animation_block();
                    Symbol *sy = a->get_parameter_symbol();
                    Game_object *g2 = sy->get_game_object_value();
                    if(g->type() == g2->type()){
                        Statement *s = new Assign_statement((Variable *) $1, (Expression *) $3, Assign_statement::EQUAL);
                        my_block_stack.top()->push_statement(s);
                        $$ = my_block_stack.top();
                    }
                    else{
                        Error::error(Error::ANIMATION_BLOCK_ASSIGNMENT_PARAMETER_TYPE_ERROR,g->type(),g2->type());
                        $$ = NULL;
                    }

                }
                else {
                    if (vt == INT || vt== DOUBLE || vt==STRING || vt==INT_ARRAY || vt == STRING_ARRAY || vt == DOUBLE_ARRAY){
                    Error::error(Error::ASSIGNMENT_TYPE_ERROR, gpl_type_to_string(vt), gpl_type_to_string(et));
                    } 
                    else {
                        if ($1->get_symbol_value()->get_type() == GAME_OBJECT) {
                            Error::error(Error::INVALID_LHS_OF_ASSIGNMENT, $1->get_symbol_name(), $1->get_symbol_value()->get_game_object_value()->type());
                        } 
                        else {
                            Error::error(Error::INVALID_LHS_OF_ASSIGNMENT, $1->get_symbol_name(), gpl_type_to_string(vt));
                        }
                    }
                }
            }
        }

    | variable T_PLUS_ASSIGN expression
    {
        if ($1 == NULL || $3 == NULL) {
                $$ = NULL;
        }  
        else{
            Gpl_type et = $3->get_type();
            Gpl_type vt = $1->get_type();
            if (((vt == INT || vt == INT_ARRAY) && et == INT)
                || ((vt == DOUBLE || vt == DOUBLE_ARRAY) && (et ==INT || et == DOUBLE))
                || (vt == STRING || vt == STRING_ARRAY) && (et == INT || et == DOUBLE || et == STRING )) {
                Statement *s = new Assign_statement((Variable *) $1, (Expression *) $3, Assign_statement::PLUS_EQUAL);
                my_block_stack.top()->push_statement(s);
                $$ = my_block_stack.top();
            } 
            else {
                if (vt == INT || vt== DOUBLE || vt==STRING || vt==INT_ARRAY || vt == STRING_ARRAY || vt == DOUBLE_ARRAY){
                Error::error(Error::PLUS_ASSIGNMENT_TYPE_ERROR, gpl_type_to_string(vt), gpl_type_to_string(et));
                } 
                else {
                    if ($1->get_symbol_value()->get_type() == GAME_OBJECT) {
                        Error::error(Error::INVALID_LHS_OF_PLUS_ASSIGNMENT, $1->get_symbol_name(), $1->get_symbol_value()->get_game_object_value()->type());
                    } 
                    else {
                        Error::error(Error::INVALID_LHS_OF_PLUS_ASSIGNMENT, $1->get_symbol_name(), gpl_type_to_string(vt));
                    }
                }
            }
        }
    }
    | variable T_MINUS_ASSIGN expression
    {
        if ($1 == NULL || $3 == NULL) {
                $$ = NULL;
        }  
        else{
            Gpl_type et = $3->get_type();
            Gpl_type vt = $1->get_type();
            if(((vt == INT || vt == INT_ARRAY) && et == INT)
                || ((vt == DOUBLE || vt == DOUBLE_ARRAY) && (et ==INT || et == DOUBLE))){
                Statement *s = new Assign_statement((Variable *) $1, (Expression *) $3, Assign_statement::MINUS_EQUAL);
                my_block_stack.top()->push_statement(s);
                $$ = my_block_stack.top();
            } 
            else{
                if (vt == INT || vt== DOUBLE || vt==INT_ARRAY || vt == DOUBLE_ARRAY){
                Error::error(Error::MINUS_ASSIGNMENT_TYPE_ERROR, gpl_type_to_string(vt), gpl_type_to_string(et));
                } 
                else {
                    if ($1->get_symbol_value()->get_type() == GAME_OBJECT) {
                        Error::error(Error::INVALID_LHS_OF_MINUS_ASSIGNMENT, $1->get_symbol_name(), $1->get_symbol_value()->get_game_object_value()->type());
                    } 
                    else {
                        Error::error(Error::INVALID_LHS_OF_MINUS_ASSIGNMENT, $1->get_symbol_name(), gpl_type_to_string(vt));
                    }
                }
            }
        }
    }   
    ;

//---------------------------------------------------------------------
variable:
    T_ID
    {
        Symbol *s = my_table->lookup(*$1);
        if(s == NULL){
            Error::error(Error::UNDECLARED_VARIABLE,*$1);
            $$ = NULL;
        }
        else{
            $$ = new Variable((Expression*)NULL,s);
        }
    }
    | T_ID T_LBRACKET expression T_RBRACKET
    {
        if($3->get_type() == DOUBLE || $3->get_type() == STRING){
            Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER,*$1,"A " + gpl_type_to_string($3->get_type())+ " expression");
            $$ = NULL;
        }
        else{
            Symbol *s = my_table->lookup(*$1);
            if(s == NULL){
                Error::error(Error::UNDECLARED_VARIABLE, *$1);
                $$ == NULL;
            }
            else{
                if(s->get_type() != STRING_ARRAY && s->get_type() != DOUBLE_ARRAY && s->get_type() != INT_ARRAY && s->get_type()!= GAME_OBJECT_ARRAY){
                    Error::error(Error::VARIABLE_NOT_AN_ARRAY, *$1);
                    $$ = NULL;
                }
                else{
                    if($3->eval_int() < 0){
                        Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS, *$1, $3->eval_string());
                        $$ = NULL;   
                    }
                    else{
                       /* if($3->eval_int() >= s->get_value()->length){
                            Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS, *$1, $3->eval_string());
                            $$ = NULL;
                        }
                        else{*/
                            $$ = new Variable($3, s);
                       // } //REMIND - Fixing test 39 p7
                    }
                }
            }
        }
        
    }
    | T_ID T_PERIOD T_ID
    {
      Symbol *s = my_table->lookup(*($1));
      if(s==NULL){
        Error::error(Error::UNDECLARED_VARIABLE, *$1);
        $$ = NULL;
      }
      else{
        if(s->is_game_object()){
            Gpl_type type;
            Game_object* g = s->get_game_object_value();
            if(g!=NULL){
                Status status = g->get_member_variable_type(*$3,type);
                if(status == OK){
                    if(type == INT){
                        int i;
                        Status stat = g->get_member_variable(*$3, i);
                        if(stat == OK){
                            $$ = new Variable(s, *$3);
                        }
                        else if(stat == MEMBER_NOT_DECLARED){
                            Error::error(Error::UNDECLARED_MEMBER, *$1, *$3);
                            $$ = NULL;  
                        }
                        else if(stat == MEMBER_NOT_OF_GIVEN_TYPE){
                            Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, *$3);
                            $$ = NULL;
                        }
                    }
                    else if(type == STRING){
                        string st;
                        Status stat = g->get_member_variable(*$3, st);
                        if(stat == OK){
                            $$ = new Variable(s, *$3);
                        }
                        else if(stat == MEMBER_NOT_DECLARED){
                            Error::error(Error::UNDECLARED_MEMBER, *$1, *$3);
                            $$ = NULL;  
                        }
                        else if(stat == MEMBER_NOT_OF_GIVEN_TYPE){
                            Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, *$3);
                            $$ = NULL;
                        }
                    }
                    else if(type == DOUBLE){
                        double d;
                        Status stat = g->get_member_variable(*$3, d);
                        if(stat == OK){
                            $$ = new Variable(s, *$3);
                        }
                        else if(stat == MEMBER_NOT_DECLARED){
                            Error::error(Error::UNDECLARED_MEMBER, *$1, *$3);
                            $$ = NULL;   
                        }
                        else if(stat == MEMBER_NOT_OF_GIVEN_TYPE){
                            Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, *$3);
                            $$ = NULL;
                        }
                    }
                    else if(type == ANIMATION_BLOCK){
                        Animation_block *a;
                        Status stat = g->get_member_variable(*$3, a);
                        if(stat == OK){
                            $$ = new Variable(s, *$3);
                        }
                        else if(stat == MEMBER_NOT_DECLARED){
                            Error::error(Error::UNDECLARED_MEMBER, *$1, *$3);
                            $$ = NULL;
                        }
                        else if(stat == MEMBER_NOT_OF_GIVEN_TYPE){
                            Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, *$3);
                            $$ = NULL;
                        }
                    }
                    else{
                        //REMIND -- might need error here
                        $$ = NULL;
                    }      
                }
                else if(status == MEMBER_NOT_DECLARED){
                    Error::error(Error::UNDECLARED_MEMBER, *$1, *$3);
                    $$ = NULL; 
                }
                else if(status == MEMBER_NOT_OF_GIVEN_TYPE){
                    Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, *$3);
                    $$ = NULL;
                }
            }
        }
        else{
            Error::error(Error::LHS_OF_PERIOD_MUST_BE_OBJECT, *$1);
            $$ = NULL;
        }
      }
    }
    | T_ID T_LBRACKET expression T_RBRACKET T_PERIOD T_ID
    {
        Symbol *s = my_table->lookup(*($1));
        if(s == NULL){
            Error::error(Error::UNDECLARED_VARIABLE, *$1);
            $$ = NULL;
        }
        else{
            if($3->get_type() != INT){
                Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER,*$1,"A " + gpl_type_to_string($3->get_type())+ " expression");
                //$$ = NULL;
            }
            //else{
                int index = $3->eval_int();
                if(s->get_type() == GAME_OBJECT_ARRAY){
                    Game_object *g = s->value->ga[0];
                    Gpl_type type;
                    if(g != NULL){
                        Status status = g->get_member_variable_type(*$6,type);
                        if(status == OK){
                           if(type == INT){
                                int i;
                                Status stat = g->get_member_variable(*$6, i);
                                if(stat == OK){
                                    $$ = new Variable(s, $3, *$6);
                                }
                                else if(stat == MEMBER_NOT_DECLARED){
                                    Error::error(Error::UNKNOWN_CONSTRUCTOR_PARAMETER, *$6);
                                    $$ = NULL;  
                                }
                                else if(stat == MEMBER_NOT_OF_GIVEN_TYPE){
                                    Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, *$6);
                                    $$ = NULL;
                                }
                            }
                            else if(type == STRING){
                                string st;
                                Status stat = g->get_member_variable(*$6, st);
                                if(stat == OK){
                                    $$ = new Variable(s, $3, *$6);
                                }
                                else if(stat == MEMBER_NOT_DECLARED){
                                    Error::error(Error::UNKNOWN_CONSTRUCTOR_PARAMETER, *$6);
                                    $$ = NULL;  
                                }
                                else if(stat == MEMBER_NOT_OF_GIVEN_TYPE){
                                    Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, *$6);
                                    $$ = NULL;
                                }
                            }
                            else if(type == DOUBLE){
                                double d;
                                Status stat = g->get_member_variable(*$6, d);
                                if(stat == OK){
                                    $$ = new Variable(s, $3, *$6);
                                }
                                else if(stat == MEMBER_NOT_DECLARED){
                                    Error::error(Error::UNKNOWN_CONSTRUCTOR_PARAMETER, *$6);
                                    $$ = NULL;  
                                }
                                else if(stat == MEMBER_NOT_OF_GIVEN_TYPE){
                                    Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, *$6);
                                    $$ = NULL;
                                }
                            }
                            else if(type == ANIMATION_BLOCK){
                                Animation_block *a;
                                Status stat = g->get_member_variable(*$6, a);
                                if(stat == OK){
                                    $$ = new Variable(s, $3, *$6);
                                }
                                else if(stat == MEMBER_NOT_DECLARED){
                                    Error::error(Error::UNKNOWN_CONSTRUCTOR_PARAMETER, *$6);
                                    $$ = NULL;  
                                }
                                else if(stat == MEMBER_NOT_OF_GIVEN_TYPE){
                                    Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, *$6);
                                    $$ = NULL;
                                }
                            }
                            else{
                                //REMIND -- might need error here
                                $$ = NULL;
                            }      
                        }
                        else if(status == MEMBER_NOT_DECLARED){
                             Error::error(Error::UNKNOWN_CONSTRUCTOR_PARAMETER, *$6);  
                             $$ = NULL;
                        }
                        else if(status == MEMBER_NOT_OF_GIVEN_TYPE){
                            Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, *$6);
                            $$ = NULL;
                        }
                    }
                    else{
                        //REMIND - might need error here
                        $$ = NULL;
                    }
                }
                else{
                    Error::error(Error::LHS_OF_PERIOD_MUST_BE_OBJECT,*$1);
                    $$ = NULL;
                }
           // }
        }
    }
    ;

//---------------------------------------------------------------------
expression:
    primary_expression
    | expression T_OR expression
    {
        if($1->get_type() != STRING && $3->get_type() != STRING){
            $$ = new Expression($1, OR, $3);
        }
        else{
            if($1->get_type() == STRING){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "||");
            }
            if($3->get_type() == STRING){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "||");
            }
            $$ = new Expression(0);
        }
    }

    | expression T_AND expression
    {
        if($1->get_type() != STRING && $3->get_type() != STRING){
            $$ = new Expression($1, AND, $3);
        }
        else{
            if($1->get_type() == STRING){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "&&");
            }
            if($3->get_type() == STRING){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "&&");
            }
            $$ = new Expression(0);
        }
    }

    | expression T_LESS_EQUAL expression
    {
        $$ = new Expression($1, LESS_THAN_EQUAL, $3);
    }

    | expression T_GREATER_EQUAL  expression
    {
        $$ = new Expression($1, GREATER_THAN_EQUAL, $3);
    }

    | expression T_LESS expression 
    {
        $$ = new Expression($1, LESS_THAN, $3);
    }

    | expression T_GREATER  expression
    {
        $$ = new Expression($1, GREATER_THAN, $3);
    }

    | expression T_EQUAL expression
    {  
        $$ = new Expression($1, EQUAL, $3);
    }

    | expression T_NOT_EQUAL expression
    {
        $$ = new Expression($1, NOT_EQUAL, $3);
    }

    | expression T_PLUS expression 
    {
        bool lhs = false;
        bool rhs = false;
        if($1->get_type() == INT || $1->get_type() == DOUBLE || $1->get_type() == STRING ){
            lhs = true;
        }
        if($3->get_type() == INT || $3->get_type() == DOUBLE || $3->get_type() == STRING ){
            rhs = true;
        }
        if(lhs && rhs){
            $$ = new Expression($1, PLUS, $3);
        }
        else{
            if(!lhs)
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE,"+");
            if(!rhs)
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"+");
            $$ = NULL;
        }
    }

    | expression T_MINUS expression
    {
        if($1->get_type() != STRING && $3->get_type() != STRING){
            $$ = new Expression($1, MINUS, $3);
        }
        else{
            if($1->get_type() == STRING){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE,"-");
            }
            if($3->get_type() == STRING){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"-");
            }
            $$ = new Expression(0);         
        }
    }

    | expression T_ASTERISK expression
    {
        if($1->get_type() != STRING && $3->get_type() != STRING){
            $$ = new Expression($1, MULTIPLY, $3);
        }
        else{
            if($1->get_type() == STRING){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE,"*");
            }
            if($3->get_type() == STRING){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"*");  
            }
            $$ = new Expression(0);
        }
    }

    | expression T_DIVIDE expression
    {
        if($1->get_type() != STRING && $3->get_type() != STRING){
            if($3->get_type() == DOUBLE && $3->eval_double() != 0){
                $$ = new Expression($1, DIVIDE, $3);
            }
            else if($3->get_type() == INT && $3->eval_int() != 0){
                $$ = new Expression($1, DIVIDE, $3);
            }
            else{
                Error::error(Error::DIVIDE_BY_ZERO_AT_PARSE_TIME);
                $$ = new Expression(0);
            }
        }
        else{
            if($1->get_type() == STRING){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "/");
            }
            if($3->get_type() == STRING){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "/");
            }
            $$ = new Expression(0);
        }
    }

    | expression T_MOD expression
    {
        if($1->get_type() == INT && $3->get_type() == INT){
            if($3->eval_int() == 0){
                Error::error(Error::MOD_BY_ZERO_AT_PARSE_TIME);
                $$ = new Expression(0);
            }
            else{
                $$ = new Expression($1,MOD,$3);
            }
        }
        else{
            if($1->get_type() != INT){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE, operator_to_string(MOD));         
            }
            if($3->get_type() != INT){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, operator_to_string(MOD));
            }
            $$ = new Expression(0);
        }
    }

    | T_MINUS expression %prec UNARY_OPS
    {
        if($2->get_type() != STRING){
            $$ = new Expression(UNARY_MINUS, $2);
        }
        else{
            $$ = new Expression(0);
        }
    }
    | T_NOT expression %prec UNARY_OPS
    {
        if($2->get_type() != STRING){
            $$ = new Expression(NOT, $2);
        }
        else{
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "!");
            $$ = new Expression(0);
        }
    }
    | math_operator T_LPAREN expression T_RPAREN
    {
        if($3->get_type() != STRING){
            $$ = new Expression($1,$3);
        }
        else{
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, operator_to_string((Operator_type)$1));
            $$ = new Expression(0);
        }
    }
    | variable geometric_operator variable{
        if($1 != NULL && $3 != NULL){
            Expression *e1 = new Expression($1);
            Expression *e2 = new Expression($3);
            if(e1->get_type() == GAME_OBJECT && e2->get_type() == GAME_OBJECT)
                $$ = new Expression(e1,$2,e2);
            Symbol *s1 = $1->get_symbol_value();
            Symbol *s2 = $3->get_symbol_value();
            if(e1->get_type()!=GAME_OBJECT){
                Error::error(Error::OPERAND_MUST_BE_A_GAME_OBJECT,s1->name);
                $$ = NULL;
            }
            if(e2->get_type()!=GAME_OBJECT){   
                Error::error(Error::OPERAND_MUST_BE_A_GAME_OBJECT,s2->name);
                $$ = NULL;
            }  
        }
        else{
            $$ = NULL;
        }

    }
    ;

//---------------------------------------------------------------------
primary_expression:
    T_LPAREN  expression T_RPAREN
    {
        $$ = $2;
    }
    | variable
    {
        if($1 != NULL){
            $$ = new Expression($1);
        }
        else{
            $$ = new Expression(0);
        }
    }
    | T_INT_CONSTANT
    {
        $$ = new Expression($1);
    }
    | T_TRUE
    {
        $$ = new Expression(1);
    }
    | T_FALSE
    {
        $$ = new Expression(0);
    }
    | T_DOUBLE_CONSTANT
    {
        $$ = new Expression($1);
    }
    | T_STRING_CONSTANT
    {
        $$ = new Expression(*$1);
    }
    ;

//---------------------------------------------------------------------
geometric_operator:
    T_TOUCHES
    {
        $$ = TOUCHES;
    }
    | T_NEAR
    {
        $$ = NEAR;
    }
    ;

//---------------------------------------------------------------------
math_operator:
    T_SIN
    {
        $$ = SIN;
    }

    | T_COS
    {
        $$ = COS;
    }

    | T_TAN
    {
        $$ = TAN;
    }

    | T_ASIN
    {
        $$ = ASIN;
    }

    | T_ACOS
    {
        $$ = ACOS;
    }

    | T_ATAN
    {
        $$ = ATAN;
    }

    | T_SQRT
    {
        $$ = SQRT;
    }

    | T_ABS
    {
        $$ = ABS;
    }

    | T_FLOOR
    {
        $$ = FLOOR;
    }

    | T_RANDOM
    {
        $$ = RANDOM;
    }

    ;

//---------------------------------------------------------------------
empty:
    // empty goes to nothing so that you can use empty in productions
    // when you want a production to go to nothing
    ;

