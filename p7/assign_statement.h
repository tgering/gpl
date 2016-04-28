#include "expression.h"
#include "variable.h"

#ifndef ASSIGN_STATEMENT_H
#define ASSIGN_STATEMENT_H

class Assign_statement: public Statement{
	public:
		enum op_type{
			EQUAL,
			PLUS_EQUAL,
			MINUS_EQUAL
		};

		Assign_statement(Variable *v, Expression *e, op_type op);
		void execute();

			private:
		Variable *m_v;
		Expression *m_e;
		op_type m_op;
};

#endif