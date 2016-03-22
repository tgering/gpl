#include "variable.h"
#include "expression.h"
#include "gpl_type.h"
#include "gpl_assert.h"
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
}

//unary expression
Expression::Expression(int token, Expression *e1){
	m_lhs = e1;
	m_rhs = NULL;
	m_oper = token;
	m_type = e1->m_type;
	m_kind = EXPRESSION;
}

//variable
Expression::Expression(Variable *v){
	m_lhs = NULL;
	m_rhs = NULL;
	m_variable = v;
	m_type = m_variable->get_type();
	m_kind = VARIABLE;
}

Gpl_type Expression::get_type(){
	return m_type;
}

int Expression::eval_int(){
	cout << "EVAL INT\n";
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
				if(m_lhs->eval_int() > m_rhs->eval_int()){
					return 1;
				}
				else{
					return 0;
				}
			case LESS_THAN:
				if(m_lhs->eval_int() < m_rhs->eval_int()){
					return 1;
				}
				else{
					return 0;
				}
			case GREATER_THAN_EQUAL:
				if(m_lhs->eval_int() >= m_rhs->eval_int()){
					return 1;
				}
				else{
					return 0;
				}
			case LESS_THAN_EQUAL:
				if(m_lhs->eval_int() <= m_rhs->eval_int()){
					return 1;
				}
				else{
					return 0;
				}
			case MOD:
				return m_lhs->eval_int() % m_rhs->eval_int();
			case UNARY_MINUS:
				return -1* m_lhs->eval_int();
			default:
				return m_lhs->eval_int();
		}
	}
}

double Expression::eval_double(){
	if(m_kind == CONSTANT){
		return m_double;
	}
	else if(m_kind == VARIABLE){
		return m_variable->get_double_value();
	}
	else{
		if(m_type == INT){
			int value = eval_int();
			double d = (double) value;
			return d;
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
				case UNARY_MINUS:
					return -1 * m_lhs->eval_double();
				default: 
					return m_lhs->eval_int();
			}
		}
	}
}

string Expression::eval_string(){
	if(m_kind == CONSTANT){
		return m_string;
	}
	else if(m_kind == VARIABLE){
		return m_variable->get_string_value();
	}
	else{
		
	}

}




