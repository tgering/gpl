#include "expression.h"
#include "variable.h"

Variable::Variable(Expression *e, Symbol *s){
	m_expression = e;
	m_symbol = s;
	m_symbol2 = NULL;
}

Variable::Variable(Symbol *s1, Symbol *s2){
	m_expression = NULL;
	m_symbol = s1;
	m_symbol2 = s2;
}

Variable::Variable(Symbol *s1, Expression *e, Symbol *s2){
	m_expression = e;
	m_symbol = s1;
	m_symbol2 = s2;
}

Gpl_type Variable::get_type(){
	if(m_symbol2 == NULL){
		return m_symbol->get_type();
	}
	else{
		return m_symbol2->get_type();
	}
}

int Variable::get_int_value(){
	if(m_symbol2 == NULL){
		V *v = m_symbol->get_value();
		return v->i;
	}
	else{
		V *v = m_symbol2->get_value();
		return v->i;
	}
}

void Variable::set_int_value(int i){
	if(m_symbol2 == NULL){
		V *v = m_symbol->get_value();
		v->i = i;
	}
	else{
		V *v = m_symbol2->get_value();
		v->i = i;
	}

}
int Variable::get_int_array_value(){
	V *v = m_symbol->get_value();
	return v->ia[m_expression->eval_int()];
}

void Variable::set_int_array_value(int i){
	V *v = m_symbol->get_value();
	v->ia[m_expression->eval_int()] = i;
}

string Variable::get_string_value(){
	if(m_symbol2 == NULL){
		V *v = m_symbol->get_value();
		return v->s;
	}
	else{
		V *v = m_symbol2->get_value();
		return v->s;
	}
}

void Variable::set_string_value(string s){
	if(m_symbol2 == NULL){
		V *v = m_symbol->get_value();
		v->s = s;
	}
	else{
		V *v = m_symbol2->get_value();
		v->s = s;
	}
}

double Variable::get_double_value(){
	if(m_symbol2 == NULL){
		V *v = m_symbol->get_value();
		return v->d;
	}
	else{
		V *v = m_symbol2->get_value();
		return v->d;
	}
}

void Variable::set_double_value(double d){
	if(m_symbol2 == NULL){
		V *v = m_symbol->get_value();
		v->d = d;
	}
	else{
		V *v = m_symbol2->get_value();
		v->d = d;
	}	
}

Animation_block* Variable::get_animation_block_value(){
	Animation_block *a = m_symbol->get_animation_block_value();
	return a;
}