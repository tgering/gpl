#include "symbol.h"
#include <sstream>

Symbol::Symbol(Game_object *go){
	g = go;
}

Symbol::Symbol(Animation_block *block){
	a = block;
}

void Symbol::print_symbol(){
	if(type == STRING){
		cout <<  gpl_type_to_string(type) << " " << name << " = \"" << value->s << "\"" << endl;
	}
	else if (type == INT_ARRAY){
		for(int y = 0; y < value->length; y++){
			cout << gpl_type_to_base_string(type) << " " << name << "[" << y << "] = " << value->ia[y] << endl;
		}
	}
	else if (type == DOUBLE_ARRAY){
		for(int y = 0; y < value->length; y++){
			cout << gpl_type_to_base_string(type) << " " << name << "[" << y << "] = " << value->da[y] << endl;
		}
	}
	else if (type == STRING_ARRAY){
		for(int y = 0; y < value->length; y++){
			cout << gpl_type_to_base_string(type) << " " << name << "[" << y << "] = \"" << value->sa[y] << "\"" << endl;
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
	else if(type == GAME_OBJECT_ARRAY){
		for(int y = 0; y < value->length; y++){
			stringstream ss;
			ss << name << "[" << y << "]";
			value->ga[y]->print(ss.str() , cout);
		}
	}
	else if(type == ANIMATION_BLOCK){
		cout << "animation_block " << name << endl;
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

void Symbol::set_game_object_value(Game_object *go){
	g=go;
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

bool Symbol::is_animation_block(){
	if(type == ANIMATION_BLOCK){
		return true;
	}
	return false;
}

Animation_block* Symbol::get_animation_block_value(){
	return a;
}




