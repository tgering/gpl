#include <iostream>
#include "if_statement.h"

	If_statement::If_statement(Statement_block *sb1, Statement_block *sb2, Expression *e){
		s1 = sb1;
		s2 = sb2;
		m_ex = e;
	}
	
	void If_statement::execute(){
		if(m_ex->eval_int()){
			s1->execute();
		}
		else if(s2!=NULL){
			s2->execute();
		}
	}