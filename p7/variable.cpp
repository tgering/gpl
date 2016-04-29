#include "expression.h"
#include "variable.h"

Variable::Variable(Expression *e, Symbol *s){
	m_expression = e;
	m_symbol = s;
	//m_s= NULL;
}

Variable::Variable(Symbol *s1, string  s){
	m_expression = NULL;
	m_symbol = s1;
	m_s = s;
}

Variable::Variable(Symbol *s1, Expression *e, string s){
	m_expression = e;
	m_symbol = s1;
	m_s = s;
}

Gpl_type Variable::get_type(){
	Gpl_type t;
	if(m_symbol->get_type()==GAME_OBJECT){
		Game_object* g = m_symbol->get_game_object_value();
		g->get_member_variable_type(m_s,t);
		return t;
	}
	else if(m_symbol->get_type() == GAME_OBJECT_ARRAY){
		Game_object* g = m_symbol->value->ga[m_expression->eval_int()];
		g->get_member_variable_type(m_s,t);
		return t;
	}
	else{
		return m_symbol->get_type();
	}
}

int Variable::get_int_value(){
	Gpl_type t = m_symbol->get_type();
	if(t == INT){
		V *v = m_symbol->get_value();
		return v->i;
	}
	else if(t == INT_ARRAY){
		V *v = m_symbol->get_value();
		return v->ia[m_expression->eval_int()];		
	}
	else if(t == GAME_OBJECT){
		int i;
		Game_object *g = m_symbol->get_game_object_value();
		g->get_member_variable(m_s,i);
		return i;
	}
	else if(t == GAME_OBJECT_ARRAY){
		int i;
		Game_object *g = m_symbol->value->ga[m_expression->eval_int()];
		g->get_member_variable(m_s,i);
		return i;
	}
}

void Variable::set_int_value(int i){
	Gpl_type t = m_symbol->get_type();
	if(t == INT){
		V *v = m_symbol->get_value();
		v->i = i;
	}
	else if(t == INT_ARRAY){
		V *v = m_symbol->get_value();
		v->ia[m_expression->eval_int()] = i;		
	}
	else if(t == GAME_OBJECT){
		Game_object *g = m_symbol->get_game_object_value();
		g->set_member_variable(m_s,i);
	}
	else if(t == GAME_OBJECT_ARRAY){
		Game_object *g = m_symbol->value->ga[m_expression->eval_int()];
		g->set_member_variable(m_s,i);
	}
}


string Variable::get_string_value(){
	Gpl_type t = m_symbol->get_type();
	if(t == STRING){
		V *v = m_symbol->get_value();
		return v->s;
	}
	else if(t == STRING_ARRAY){
		V *v = m_symbol->get_value();
		return v->sa[m_expression->eval_int()];		
	}
	else if(t == GAME_OBJECT){
		string i;
		Game_object *g = m_symbol->get_game_object_value();
		g->get_member_variable(m_s,i);
		return i;
	}
	else if(t == GAME_OBJECT_ARRAY){
		string i;
		Game_object *g = m_symbol->value->ga[m_expression->eval_int()];
		g->get_member_variable(m_s,i);
		return i;
	}
}

void Variable::set_string_value(string s){
	Gpl_type t = m_symbol->get_type();
	if(t == STRING){
		V *v = m_symbol->get_value();
		v->s = s;
	}
	else if(t == STRING_ARRAY){
		V *v = m_symbol->get_value();
		v->sa[m_expression->eval_int()] = s;		
	}
	else if(t == GAME_OBJECT){
		Game_object *g = m_symbol->get_game_object_value();
		g->set_member_variable(m_s,s);
	}
	else if(t == GAME_OBJECT_ARRAY){
		Game_object *g = m_symbol->value->ga[m_expression->eval_int()];
		g->set_member_variable(m_s,s);
	}
}


double Variable::get_double_value(){
	Gpl_type t = m_symbol->get_type();
	if(t == DOUBLE){
		V *v = m_symbol->get_value();
		return v->d;
	}
	else if(t == DOUBLE_ARRAY){
		V *v = m_symbol->get_value();
		return v->da[m_expression->eval_int()];		
	}
	else if(t == GAME_OBJECT){
		double i;
		Game_object *g = m_symbol->get_game_object_value();
		g->get_member_variable(m_s,i);
		return i;
	}
	else if(t == GAME_OBJECT_ARRAY){
		double i;
		Game_object *g = m_symbol->value->ga[m_expression->eval_int()];
		g->get_member_variable(m_s,i);
		return i;
	}
}


void Variable::set_double_value(double d){
	Gpl_type t = m_symbol->get_type();
	if(t == DOUBLE){
		V *v = m_symbol->get_value();
		v->d = d;
	}
	else if(t == DOUBLE_ARRAY){
		V *v = m_symbol->get_value();
		v->da[m_expression->eval_int()] = d;		
	}
	else if(t == GAME_OBJECT){
		Game_object *g = m_symbol->get_game_object_value();
		g->set_member_variable(m_s,d);
	}
	else if(t == GAME_OBJECT_ARRAY){
		Game_object *g = m_symbol->value->ga[m_expression->eval_int()];
		g->set_member_variable(m_s,d);
	}
}

Animation_block* Variable::get_animation_block_value(){
	Animation_block *a = m_symbol->get_animation_block_value();
	return a;
}