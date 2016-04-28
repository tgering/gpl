#include "assign_statement.h"
#include <iostream>

Assign_statement::Assign_statement(Variable *v, Expression *e, op_type op){
	m_v = v;
	m_e = e;
	m_op = op;
}

void Assign_statement::execute(){
	if(m_op == EQUAL){
		if(m_v->get_type() == INT){
			m_v->set_int_value(m_e->eval_int());
		}
		else if(m_v->get_type() == STRING){
			m_v->set_string_value(m_e->eval_string());
		}
		else if(m_v->get_type() == DOUBLE){
			m_v->set_double_value(m_e->eval_double());
		}
		else if(m_v->get_type() == INT_ARRAY){
			m_v->set_int_array_value(m_e->eval_int());
		}
	}
	else if(m_op == PLUS_EQUAL){
		if(m_v->get_type() == INT){
			m_v->set_int_value(m_v->get_int_value() + m_e->eval_int());
		}
		else if(m_v->get_type() == STRING){
			m_v->set_string_value(m_v->get_string_value() + m_e->eval_string());
		}
		else if(m_v->get_type() == DOUBLE){
			m_v->set_double_value(m_v->get_double_value() + m_e->eval_double());
		}
		else if(m_v->get_type() == INT_ARRAY){
			
		}

	}
	else if(m_op == MINUS_EQUAL){
		if(m_v->get_type() == INT){
			m_v->set_int_value(m_v->get_int_value() - m_e->eval_int());
		}
		else if(m_v->get_type() == DOUBLE){
			m_v->set_double_value(m_v->get_double_value() - m_e->eval_double());
		}
		else if(m_v->get_type() == ARRAY){
			
		}

	}
}
