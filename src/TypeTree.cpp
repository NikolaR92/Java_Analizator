#include "TypeTree.hpp"

TypeTree :: ~TypeTree(){

}

string IntType :: getType() const{
	return "int";
}

string FloatType :: getType()const{
	return "float";
}

string CharType:: getType()const{
	return "char";
}

string ArrayType:: getType()const{
	return "array";
}

TypeTree* ArrayType:: getTip(){
	return _tip;
}

int ArrayType::getSize(){
	return _size;
}

string MatrixType:: getType()const{
	return "matrix";
}

TypeTree* MatrixType::getTip(){
	return _tip;
}

int MatrixType::getSize1(){
	return _size1;
}

int MatrixType::getSize2(){
	return _size2;
}

string ObjectType:: getType()const{
	return _name;
}

string BooleanType:: getType() const{
	return "boolean";
}

