#include "symbol_table.h"
#include "symbol.h"

/* static */ Symbol_table *Symbol_table::m_instance = 0;

/* static */ Symbol_table * Symbol_table::instance()
{
  if (m_instance == 0)
    m_instance = new Symbol_table();
  return m_instance;
}

void Symbol_table::print(ostream &os){
	map<string,Symbol*> om;
	
	for(unordered_map<string,Symbol*>::const_iterator i = m.begin(); i != m.end(); i++){
		pair<string,Symbol*> p(i->first,i->second);
		om.insert(p);
	}
	for(map<string,Symbol*>::const_iterator it = om.begin(); it != om.end(); it++){
		it->second->print_symbol();
	}
}

Symbol* Symbol_table::lookup(string name){
	unordered_map<string,Symbol*>::const_iterator i = m.find(name);
	if(i == m.end()){
		return NULL;
	}
	else{
		return i->second;
	}
}

void Symbol_table::insert(string key, Symbol* s){
	pair<string,Symbol*> mypair(key,s);
	m.insert(mypair);
}