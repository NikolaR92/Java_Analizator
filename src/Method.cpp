#include "Method.hpp"

TypeTree* Type :: getType(){
	return _type;
}

string Type :: getName(){
	return _name;
}

void Method :: addType(Type t){
	_parametri.push_back(t);
}

void Method :: addReturnType(TypeTree* r){
	_returnType=r;
}

string Method :: getName(){
	return _name;
}
