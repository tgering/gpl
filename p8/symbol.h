#ifndef SYMBOL_H
#define SYMBOL_H
#include <iostream>
#include <vector>
#include "gpl_type.h"
#include "game_object.h"
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include "pixmap.h"
#include "textbox.h"

using namespace std;

class V {
public:
 int length;
 int i;
 double d;
 string s;
 int* ia;
 string* sa;
 double* da;
 vector<Game_object*> ga;
 V(int x) { i = x;}
 V(string x) {s = x;}
 V(double x) {d = x;}
 V(Gpl_type array_type, int size) 
 {
 	length = size;
 	if(array_type == INT_ARRAY){
 		ia = new int[size];
 		for(int y = 0; y < size; y++){
 			ia[y] = 0;
 		}
 	}
 	else if(array_type == STRING_ARRAY){
 		sa = new string[size];
 		for(int y = 0; y < size; y++){
 			sa[y] = "";
 		}
 	}
 	else if(array_type == DOUBLE_ARRAY){
 		da = new double[size];
 		for(int y = 0; y < size; y++){
 			da[y] = 0.0;
 		}
 	}
 	else if(array_type == CIRCLE){
 		//ga = new Circle[size];
 		for(int y = 0; y < size; y++){
 			ga.push_back(new Circle());
 		}
 	}
 	else if(array_type == TRIANGLE){
 		//ga = new Triangle[size];
 		for(int y = 0; y < size; y++){
 			ga.push_back(new Triangle());
 		}
 	}
 	else if(array_type == PIXMAP){
 		//ga = new Pixmap[size];
 		for(int y = 0; y < size; y++){
 			ga.push_back(new Pixmap());
 		}
 	}
 	else if(array_type == RECTANGLE){
 	
 		for(int y = 0; y < size; y++){
 			 ga.push_back(new Rectangle());
 		}
 	}
 	
 	else if(array_type == TEXTBOX){
 		//ga = new Textbox[size];
 		for(int y = 0; y < size; y++){
 			ga.push_back(new Textbox());
 		}
 	}
 }
};

class Symbol
{
	public:
		Symbol(Game_object *go);
		Symbol(Animation_block *block);
		Symbol(){};
		void set(int x);
		void print_symbol();
		string get_name();
		Gpl_type get_type();
		V* get_value();
		string name;
		Gpl_type type;
		V* value;
		Game_object* get_game_object_value();
		void set_game_object_value(Game_object *go);
		bool is_animation_block();
		Animation_block* get_animation_block_value();
		void set_animation_block_value(Animation_block *ab);
		bool is_game_object();
		int get_int_value();
		double get_double_value();
		string get_string_value();
	private:
		Game_object *g;
		Animation_block *a;
};

#endif