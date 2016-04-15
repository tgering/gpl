#ifndef VARIABLE_H
#define VARIABLE_H

#include "symbol.h"
#include <iostream>
using namespace std;

class Expression;

class Variable{
	public:
		Variable(Expression *e, Symbol *s);
		Gpl_type get_type();
		int get_int_value();
		string get_string_value();
		double get_double_value();
		Animation_block* get_animation_block_value();
	private:
		Expression *m_expression;
		Symbol *m_symbol;
};

#endif