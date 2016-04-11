#include "expression.h"
#include "variable.h"

Variable::Variable(Expression *e, Symbol *s){
	m_expression = e;
	m_symbol = s;
}

Gpl_type Variable::get_type(){
	return m_symbol->get_type();
}

int Variable::get_int_value(){
		V *v = m_symbol->get_value();
		return v->i;

}

string Variable::get_string_value(){
	V *v = m_symbol->get_value();
	return v->s;
}

double Variable::get_double_value(){
	V *v = m_symbol->get_value();
	return v->d;
}