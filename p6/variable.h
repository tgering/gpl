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
		string get_string_value();
		double get_double_value();
		Animation_block* get_animation_block_value();
	private:
		Expression *m_expression;
		Symbol *m_symbol;
		Symbol *m_symbol2;
};

#endif