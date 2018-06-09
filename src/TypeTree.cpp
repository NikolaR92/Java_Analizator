#include "TypeTree.hpp"


string TypeTree :: getModifier() const{
	return _modifier;
}

TypeTree :: ~TypeTree(){

}

string IntType :: getType() const{
	return "int";
}

string DoubleType :: getType()const{
	return "double";
}

string CharType:: getType()const{
	return "char";
}

string ArrayType:: getType()const{
	return _"array";
}

TypeTree* ArrayType:: getTip(){
	return _tip;
}

int ArrayType::getSize(){
	return _size;
}



string ObjectType:: getType()const{
	return _name;
}

string BooleanType:: getType() const{
	return "boolean";
}

