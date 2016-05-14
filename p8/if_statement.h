#include "expression.h"

#ifndef IF_STATEMENT_H
#define IF_STATEMENT_H

class If_statement: public Statement{
	public:
		If_statement(Statement_block *sb1, Statement_block *sb2, Expression *e);
		void execute();
	private:
		Statement_block *s1;
		Statement_block *s2;
		Expression *m_ex;
};

#endif