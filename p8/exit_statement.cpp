#include <iostream>
#include "exit_statement.h"

Exit_statement::Exit_statement(Expression *ex, int line){
	m_ex = ex;
	line_number = line;
}

void Exit_statement::execute(){
	int i = m_ex->eval_int();
	cout << "gpl[" << line_number << "]: exit(" << i << ")" << endl;
	exit(i);
}