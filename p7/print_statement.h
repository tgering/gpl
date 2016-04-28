#include "statement.h"
#include "expression.h"

#ifndef PRINT_STATEMENT_H
#define PRINT_STATEMENT_H
class Print_Statement: public Statement{
	public:
		Print_Statement(Expression *ex, int line);
		void execute();
	private:
		Expression *m_ex;
		int line_number;
};
#endif