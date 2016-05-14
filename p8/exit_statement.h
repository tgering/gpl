#include "statement.h"
#include "expression.h"

#ifndef EXIT_STATEMENT_H
#define EXIT_STATEMENT_H

class Exit_statement: public Statement{
	public:
		Exit_statement(Expression *ex, int line);
		void execute();
	private:
		Expression *m_ex;
		int line_number;
};

#endif