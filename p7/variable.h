#ifndef VARIABLE_H
#define VARIABLE_H

#include "symbol.h"
#include <iostream>
using namespace std;

class Expression;

class Variable{
	public:
		Variable(Expression *e, Symbol *s);
		Variable(Symbol *s1, Symbol *s2);
		Variable(Symbol *s1, Expression *e, Symbol *s2);
		Gpl_type get_type();
		int get_int_value();
		int get_int_array_value();
		void set_int_array_value(int i);
		void set_int_value(int i);
		string get_string_value();
		void set_string_value(string s);
		double get_double_value();
		void set_double_value(double d);
		Animation_block* get_animation_block_value();
	private:
		Expression *m_expression;
		Symbol *m_symbol;
		Symbol *m_symbol2;
};

#endif