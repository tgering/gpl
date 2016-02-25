#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include <iostream>
#include <unordered_map>
#include <map>
#include "symbol.h"
using namespace std;


// class Symbol_table is a singleton
class Symbol_table
{
  public:
    static Symbol_table *instance();
    void print(ostream &os);
    void insert(string key, Symbol* s);
    Symbol* lookup(string name);  
  private:
    static Symbol_table *m_instance;
    Symbol_table() {};

    // disable default copy constructor and default assignment
    // done as a precaution, they should never be called
    Symbol_table(const Symbol_table &);
    const Symbol_table &operator=(const Symbol_table &);
    unordered_map<string,Symbol*> m;
};

#endif










