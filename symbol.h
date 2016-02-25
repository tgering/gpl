#ifndef SYMBOL_H
#define SYMBOL_H
#include <iostream>
#include "gpl_type.h"
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
 V(int x) { i =x;}
 V(string x) {s =x;}
 V(double x) {d = x;}
 V(Gpl_type array_type, int size) 
 {
 	length = size;
 	if(array_type == INT_ARRAY){
 		ia = new int[size];
 		for(int i = 0; i < size; i++){
 			ia[i] = 42;
 		}
 	}
 	else if(array_type == STRING_ARRAY){
 		sa = new string[size];
 		for(int i = 0; i < size; i++){
 			sa[i] = "Hello world";
 		}
 	}
 	else if(array_type == DOUBLE_ARRAY){
 		da = new double[size];
 		for(int i = 0; i < size; i++){
 			da[i] = 3.14159;
 		}
 	}
 }
};

class Symbol
{
	public:
		void print_symbol();
		string get_name();
		Gpl_type get_type();
		V* get_value();
		string name;
		Gpl_type type;
		V* value;

	private:
		
};

#endif