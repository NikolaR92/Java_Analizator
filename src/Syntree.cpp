#include "Syntree.hpp"


SynTree:: ~SynTree(){

}

void ConstIntST :: fill_table(string class_name,int location) const{

}

TypeTree* ConstIntST :: check() const{

	return NULL;
}

void ConstFloatST :: fill_table(string class_name,int location) const{

}

TypeTree* ConstFloatST :: check() const{

	return NULL;
}


void ConstCharST :: fill_table(string class_name,int location) const{

}

TypeTree* ConstCharST:: check() const{

	return NULL;
}

void ConstBooleanST :: fill_table(string class_name,int location) const{

}

TypeTree* ConstBooleanST :: check() const{
	return NULL;
}

void VariableST :: fill_table(string class_name,int location) const{

}

TypeTree* VariableST :: check() const{

	return NULL;
}


void VariableDeclaration :: fill_table(string class_name,int location) const{

}

TypeTree* VariableDeclaration :: check() const{
	return NULL;
}

void MethodDeclaration :: fill_table(string class_name,int location) const{

}

TypeTree* MethodDeclaration :: check() const{
	return NULL;
}

void ClassDeclaration :: fill_table(string class_name,int location) const{

}

TypeTree* ClassDeclaration :: check() const{
	return NULL;
}


void ClassDeclarationExtends :: fill_table(string class_name,int location) const{

}

TypeTree* ClassDeclarationExtends :: check() const{
	return NULL;
}

void Package :: fill_table(string class_name,int location) const{

}

TypeTree* Package :: check() const{
	return NULL;
}

void Import :: fill_table(string class_name,int location) const{

}

TypeTree* Import :: check() const{
	return NULL;
}


