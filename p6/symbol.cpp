#include "symbol.h"


void Symbol::print_symbol(){
	if(type == STRING){
		cout <<  gpl_type_to_string(type) << " " << name << " = \"" << value->s << "\"" << endl;
	}
	else if (type == INT_ARRAY){
		for(int i = 0; i < value->length; i++){
			cout << gpl_type_to_base_string(type) << " " << name << "[" << i << "] = " << value->ia[i] << endl;
		}
	}
	else if (type == DOUBLE_ARRAY){
		for(int i = 0; i < value->length; i++){
			cout << gpl_type_to_base_string(type) << " " << name << "[" << i << "] = " << value->da[i] << endl;
		}
	}
	else if (type == STRING_ARRAY){
		for(int i = 0; i < value->length; i++){
			cout << gpl_type_to_base_string(type) << " " << name << "[" << i << "] = \"" << value->sa[i] << "\"" << endl;
		}
	}
	else if (type == INT){
		cout <<  gpl_type_to_string(type) << " " << name << " = " << value->i << endl;
	}
	else if (type == DOUBLE){
		cout << gpl_type_to_string(type) << " " << name << " = " << value->d << endl;
	}
	
}

string Symbol::get_name(){
	return name;
}

Gpl_type Symbol::get_type(){
	return type;
}

V* Symbol::get_value(){
	return value;
}