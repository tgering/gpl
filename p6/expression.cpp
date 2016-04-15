#include "variable.h"
#include "expression.h"
#include "gpl_type.h"
#include "gpl_assert.h"
#include <sstream>
#include <tgmath.h>
//int
Expression::Expression(int i){
	m_lhs = NULL;
	m_rhs = NULL;
	m_variable = NULL;
	m_type = INT;
	m_int = i;
	m_kind = CONSTANT;
}

//double
Expression::Expression(double d){
	m_lhs = NULL;
	m_rhs = NULL;
	m_variable = NULL;
	m_type = DOUBLE;
	m_double = d;
	m_kind = CONSTANT;
}

//string
Expression::Expression(string s){
	m_lhs = NULL;
	m_rhs = NULL;
	m_variable = NULL;
	m_type = STRING;
	m_string = s;
	m_kind = CONSTANT;
}

//binary expression
Expression::Expression(Expression* e1, int token, Expression *e2){
	m_lhs = e1;
	m_rhs = e2;
	m_variable = NULL;
	m_oper = token;
	m_kind = EXPRESSION;
	if(e1->m_type == INT && e2->m_type == INT){
		m_type = INT;
	}
	else if(e1->m_type == STRING || e2->m_type == STRING){
		m_type = STRING;
	}
	else if(e1->m_type == DOUBLE || e2->m_type == DOUBLE){		//since we kow that neither type is string, if type is not double, it must be int
		m_type = DOUBLE;
	}
	switch(token){
		case EQUAL:
		case GREATER_THAN:
		case GREATER_THAN_EQUAL:
		case LESS_THAN:
		case LESS_THAN_EQUAL:
		case AND:
		case OR:
		case NOT_EQUAL:
			m_type = INT;
			break;
		default:
			break;
	}
}

//unary expression
Expression::Expression(int token, Expression *e1){
	m_lhs = e1;
	m_rhs = NULL;
	m_oper = token;
	m_kind = EXPRESSION;
	switch(m_oper){
		case SIN:
		case COS:
		case TAN:
		case ACOS:
		case ASIN:
		case ATAN:
		case SQRT:
			m_type = DOUBLE;
			break;
		case ABS:
			m_type = e1->get_type();
			break;
		case FLOOR:
		case RANDOM:
		case NOT:
			m_type = INT;
			break;
		default:
			m_type = e1->get_type();
			break;
	}
}

//variable
Expression::Expression(Variable *v){
	m_lhs = NULL;
	m_rhs = NULL;
	m_variable = v;
	m_type = m_variable->get_type();
	switch(m_type){
		case INT_ARRAY:
			m_type = INT;
			break;
		case STRING_ARRAY:
			m_type = STRING;
			break;
		case DOUBLE_ARRAY:
			m_type = DOUBLE;
			break;
		default:
			m_type = m_type;
			break;
	}
	m_kind = VARIABLE;
}

Gpl_type Expression::get_type(){
	return m_type;
}

int Expression::eval_int(){
	if(m_kind == CONSTANT){
		return m_int;
	}
	else if(m_kind == VARIABLE){	
		return m_variable->get_int_value();
	}
	else{
		assert(m_type == INT);
		switch(m_oper){
			case PLUS:
				return m_rhs->eval_int() + m_lhs->eval_int();
			case MINUS:
					return m_lhs->eval_int() - m_rhs->eval_int();		
			case MULTIPLY:
				return m_lhs->eval_int() * m_rhs->eval_int();
			case DIVIDE:
				return m_lhs->eval_int() / m_rhs->eval_int();
			case GREATER_THAN:
				if(m_lhs->get_type() == STRING || m_rhs->get_type() == STRING){
					return m_lhs->eval_string() > m_rhs->eval_string();
				}
				else if(m_lhs->get_type() == DOUBLE || m_rhs->get_type() == DOUBLE){
					return m_lhs->eval_double() > m_rhs->eval_double();
				}
				else{
					return m_lhs->eval_int() > m_rhs->eval_int();	
				}
			case LESS_THAN:
				if(m_lhs->get_type() == STRING || m_rhs->get_type() == STRING){
					return m_lhs->eval_string() < m_rhs->eval_string();
				}
				else if(m_lhs->get_type() == DOUBLE || m_rhs->get_type() == DOUBLE){
					return m_lhs->eval_double() < m_rhs->eval_double();
				}
				else{
					return m_lhs->eval_int() < m_rhs->eval_int();	
				}
			case GREATER_THAN_EQUAL:
				if(m_lhs->get_type() == STRING || m_rhs->get_type() == STRING){
					return m_lhs->eval_string() >= m_rhs->eval_string();
				}
				else if(m_lhs->get_type() == DOUBLE || m_rhs->get_type() == DOUBLE){
					return m_lhs->eval_double() >= m_rhs->eval_double();
				}
				else{
					return m_lhs->eval_int() >= m_rhs->eval_int();	
				}
			case LESS_THAN_EQUAL:
				if(m_lhs->get_type() == STRING || m_rhs->get_type() == STRING){
					return m_lhs->eval_string() <= m_rhs->eval_string();
				}
				else if(m_lhs->get_type() == DOUBLE || m_rhs->get_type() == DOUBLE){
					return m_lhs->eval_double() <= m_rhs->eval_double();
				}
				else{
					return m_lhs->eval_int() <= m_rhs->eval_int();	
				}
			case NOT_EQUAL:
				if(m_lhs->get_type() == STRING || m_rhs->get_type() == STRING){
					return m_lhs->eval_string() != m_rhs->eval_string();
				}
				else if(m_lhs->get_type() == DOUBLE || m_rhs->get_type() == DOUBLE){
					return m_lhs->eval_double() != m_rhs->eval_double();
				}
				else{
					return m_lhs->eval_int() != m_rhs->eval_int();	
				}
			case MOD:
				return m_lhs->eval_int() % m_rhs->eval_int();
			case UNARY_MINUS:
				return -1* m_lhs->eval_int();
			case RANDOM:
				return rand() % m_lhs->eval_int();
			case NOT:
				if(m_lhs->get_type() == INT){
					return !m_lhs->eval_int();
				}
				else if(m_lhs->get_type() == DOUBLE){
					return !m_lhs->eval_double();
				}
			case AND:
				if(m_lhs->get_type() == DOUBLE || m_rhs->get_type() == DOUBLE){
					return m_lhs->eval_double() && m_rhs->eval_double();
				}
				else if (m_lhs->get_type() == INT && m_rhs->get_type() == INT){
					return m_lhs->eval_int() && m_rhs->eval_int();	
				}
			case OR:
				if(m_lhs->get_type() == DOUBLE || m_rhs->get_type() == DOUBLE){
					return m_lhs->eval_double() || m_rhs->eval_double();
				}
				else if (m_lhs->get_type() == INT && m_rhs->get_type() == INT){
					return m_lhs->eval_int() || m_rhs->eval_int();	
				}
			case FLOOR:
				return floor(m_lhs->eval_double());
			case ABS:
				return abs(m_lhs->eval_int());
			case EQUAL:
				if(m_lhs->get_type() == STRING || m_rhs->get_type() == STRING){
					return m_lhs->eval_string() == m_rhs->eval_string();
				}
				else if(m_lhs->get_type() == DOUBLE || m_rhs->get_type() == DOUBLE){
					return m_lhs->eval_double() == m_rhs->eval_double();
				}
				else{
					return m_lhs->eval_int() == m_rhs->eval_int();	
				}
			default:
				return m_lhs->eval_int();
		}
	}
}

double Expression::eval_double(){
	if(m_type == INT){
		int value = eval_int();
		double d = (double) value;
		return d;
	}
	if(m_kind == CONSTANT){
		return m_double;
	}
	else if(m_kind == VARIABLE){
		return m_variable->get_double_value();
	}
	else{
		assert(m_type == DOUBLE);
		switch(m_oper){
			case PLUS:
				return m_lhs->eval_double() + m_rhs->eval_double();
			case MINUS:
				return m_lhs->eval_double() - m_rhs->eval_double();
			case MULTIPLY:
				return m_lhs->eval_double() * m_rhs->eval_double();
			case DIVIDE:
				return m_lhs->eval_double() / m_rhs->eval_double();
			case SIN:
				return sin(m_lhs->eval_double() * M_PI/180);
			case COS:
				return cos(m_lhs->eval_double() * M_PI/180);
			case TAN:
				return tan(m_lhs->eval_double() * M_PI/180);
			case ASIN:
				return asin(m_lhs->eval_double()) * 180/M_PI;
			case ACOS:
				return acos(m_lhs->eval_double()) * 180/M_PI;
			case ATAN:
				return atan(m_lhs->eval_double()) * 180/M_PI;
			case SQRT:
				return sqrt(m_lhs->eval_double());
			case ABS:
				return fabs(m_lhs->eval_double());
			case UNARY_MINUS:
				return -1 * m_lhs->eval_double();
			default: 
				return m_lhs->eval_int();
		}
	}
}

string Expression::eval_string(){
	if(m_type == INT){
		int val = eval_int();
		stringstream ss;
		ss << val;
		return ss.str();
	}
	if(m_type == DOUBLE){
		double val = eval_double();
		stringstream ss;
		ss << val;
		return ss.str();
	}
	if(m_kind == CONSTANT){
		return m_string;
	}
	else if(m_kind == VARIABLE){
		return m_variable->get_string_value();
	}
	else{
		switch(m_oper){
			case PLUS:
				return m_lhs->eval_string() + m_rhs->eval_string();
		}
	}

}

Animation_block* Expression::eval_animation_block(){
	m_variable->get_animation_block_value();
}




