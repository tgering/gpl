#include "expression.h"
#include "statement_block.h"
#ifndef FOR_STATEMENT_H
#define FOR_STATEMENT_H

class For_statement: public Statement{
	public:
		For_statement(Statement_block *init, Statement_block *increment, Statement_block *body, Expression *e);
		void execute();
	private:
		Statement_block *m_init;
		Statement_block *m_increment;
		Statement_block *m_body;
		Expression *m_e;
};
#endif