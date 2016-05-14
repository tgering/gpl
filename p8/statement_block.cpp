// updated 2/14/16

#include "statement_block.h"
#include "print_statement.h"
#include "gpl_assert.h"
using namespace std;


Statement_block::Statement_block()
{

}

// this function is called for all non-animation_block statement_blocks
// Implement it for p7
void Statement_block::execute()
{
	//for(vector<Statement*>::iterator it = v.begin(); it != v.end(); it++){
	for(int i = 0; i < v.size(); i++){
		v[i]->execute();
	}
}

void Statement_block::push_statement(Statement *s){
	v.push_back(s);
}