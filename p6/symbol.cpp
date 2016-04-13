#include "symbol.h"

Symbol::Symbol(Game_object *go){
	g = go;
}

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
	else if (type == GAME_OBJECT){
		g->print(name, cout);
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

Game_object* Symbol::get_game_object_value(){
	return g;
}

bool Symbol::is_game_object(){
	if(type == GAME_OBJECT){
		return true;
	}
	return false;
}

int Symbol::get_int_value(){
	return value->i;
}

double Symbol::get_double_value(){
	return value->d;
}
		
string Symbol::get_string_value(){
	return value->s;
}

void Symbol::set(int x){
	value->i = x;
}




