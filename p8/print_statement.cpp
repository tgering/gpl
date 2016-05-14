#include <iostream>
#include "print_statement.h"
using namespace std;

Print_Statement::Print_Statement(Expression *ex, int line){
	m_ex = ex;
	line_number = line;
}

void Print_Statement::execute(){
	string s = m_ex->eval_string();
	cout << "print[" << line_number << "]: " << s << endl;
}