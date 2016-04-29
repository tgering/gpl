#include "for_statement.h"
using namespace std;


For_statement::For_statement(Statement_block *init, Statement_block *increment, Statement_block *body, Expression *e){
	m_init = init;
	m_increment = increment;
	m_body = body;
	m_e = e;
}

void For_statement::execute(){
	m_init->execute();
	while(m_e->eval_int()){
		m_body->execute();
		m_increment->execute();
	}
}