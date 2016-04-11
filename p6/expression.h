#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "gpl_type.h"
#include <iostream>
using namespace std;

class Variable;

class Expression{
	public:
		Expression(int i);
		Expression(double d);
		Expression(string s);
		Expression(Expression* e1, int token, Expression *e2);
		Expression(int token, Expression *e1);
		Expression(Variable *v);
		Gpl_type get_type();
		int eval_int();
		double eval_double();
		string eval_string();

	private:
		Expression *m_lhs;
		Expression *m_rhs;
		Variable *m_variable;
		enum Tree_kind{EXPRESSION,CONSTANT,VARIABLE};
		Tree_kind m_kind;
		int m_oper;
		Gpl_type m_type;
		int m_int;
		string m_string;
		double m_double;
};

#endif