#include "InnerSynTree.hpp"

//Konstuktori za unutrasnje drvo
InnerSynTree:: InnerSynTree(SynTree* a){
	_nodes.resize(0);
	_nodes.push_back(a);
}

InnerSynTree:: InnerSynTree(SynTree *a, SynTree* b){
	_nodes.resize(0);
	_nodes.push_back(a);
	_nodes.push_back(b);
}

InnerSynTree:: InnerSynTree(SynTree *a, SynTree* b, SynTree* c){
	_nodes.resize(0);
	_nodes.push_back(a);
	_nodes.push_back(b);
	_nodes.push_back(c);
}

InnerSynTree:: InnerSynTree(SynTree* a, SynTree* b, SynTree* c, SynTree *d){
	_nodes.resize(0);
	_nodes.push_back(a);
	_nodes.push_back(b);
	_nodes.push_back(c);
	_nodes.push_back(d);
}

InnerSynTree:: InnerSynTree(vector<SynTree*> a){
	_nodes=a;
}

InnerSynTree:: ~InnerSynTree(){
	for(unsigned i=0;i<_nodes.size();i++)
		delete _nodes[i];
}

//check metoda za operacije
void AddSynTree :: fill_table(string class_name,int location) const{

}

TypeTree* AddSynTree:: check() const{
	return NULL;
}

void SubSynTree :: fill_table(string class_name,int location) const{

}

TypeTree* SubSynTree:: check() const{
	return NULL;
}

void MulSynTree :: fill_table(string class_name,int location) const{

}

TypeTree* MulSynTree:: check() const{
	return NULL;
}

void DivSynTree :: fill_table(string class_name,int location) const{

}

TypeTree* DivSynTree:: check() const{
	return NULL;
}

void ModSynTree :: fill_table(string class_name,int location) const{

}

TypeTree* ModSynTree:: check() const{
	return NULL;
}

void LTESynTree :: fill_table(string class_name,int location) const{

}

TypeTree* LTESynTree:: check() const{
	return NULL;
}

void GTESynTree :: fill_table(string class_name,int location) const{

}

TypeTree* GTESynTree:: check() const{
	return NULL;
}

void AssignSynTree :: fill_table(string class_name,int location) const{

}

TypeTree* AssignSynTree:: check() const{
	return NULL;
}

void AndSynTree :: fill_table(string class_name,int location) const{

}

TypeTree* AndSynTree:: check() const{
	return NULL;
}

void OrSynTree :: fill_table(string class_name,int location) const{

}

TypeTree* OrSynTree:: check() const{
	return NULL;
}


//check opcija za kontrolu toka
void IfSynTree :: fill_table(string class_name,int location) const{

}

TypeTree* IfSynTree:: check() const{
	return NULL;
}

void IfThenSynTree :: fill_table(string class_name,int location) const{

}

TypeTree* IfThenSynTree:: check() const{
	return NULL;
}

void ForSynTree :: fill_table(string class_name,int location) const{

}

TypeTree* ForSynTree:: check() const{
	return NULL;
}

void WhileSynTree :: fill_table(string class_name,int location) const{

}

TypeTree* WhileSynTree :: check() const{
	return NULL;
}

void DoWhileSynTree :: fill_table(string class_name,int location) const{

}

TypeTree* DoWhileSynTree :: check() const{
	return NULL;
}


void ArrayAssignSynTree :: fill_table(string class_name,int location) const{

}

TypeTree* ArrayAssignSynTree :: check() const{
	return NULL;
}

void PrintST :: fill_table(string class_name,int location) const{

}

TypeTree* PrintST :: check() const{
return NULL;
}
