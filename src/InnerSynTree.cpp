#include "InnerSynTree.hpp"

extern stack<map<string,HashT*>> stek_promenljivih;
extern map<string, vector<Method>> spisak_metoda;

//privremeno skladiste kada se nalazi vise promenljivih odjednom u redu
extern vector<string> niz;
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

void PrefixAdd :: fill_table(string class_name,string method) const{

}

TypeTree* PrefixAdd:: check(string class_name,string method) const{
	TypeTree* tip = _nodes[0]->check(class_name,method);
	if(tip->getType()!="int" && tip->getType()!="double")
			cerr<<"Operacija ++ nad tipom "<<tip->getType()<<" nije dozvoljena"<<endl;

	return _nodes[0]->check(class_name,method);
}

void PrefixSub :: fill_table(string class_name,string method) const{

}

TypeTree* PrefixSub:: check(string class_name,string method) const{
	TypeTree* tip = _nodes[0]->check(class_name,method);
		if((tip->getType()!="int") && (tip->getType()!="double"))
				cerr<<"Operacija -- nad tipom "<<tip->getType()<<" nije dozvoljena"<<endl;

		return _nodes[0]->check(class_name,method);
}

void PostfixAdd :: fill_table(string class_name,string method) const{

}

TypeTree* PostfixAdd:: check(string class_name,string method) const{
	TypeTree* tip = _nodes[0]->check(class_name,method);
		if((tip->getType()!="int") && (tip->getType()!="double"))
				cerr<<"Operacija ++ nad tipom "<<tip->getType()<<" nije dozvoljena"<<endl;

		return _nodes[0]->check(class_name,method);
}

void PostfixSub :: fill_table(string class_name,string method) const{

}

TypeTree* PostfixSub:: check(string class_name,string method) const{
	TypeTree* tip = _nodes[0]->check(class_name,method);
		if((tip->getType()!="int") && (tip->getType()!="double"))
				cerr<<"Operacija ++ nad tipom "<<tip->getType()<<" nije dozvoljena"<<endl;

		return _nodes[0]->check(class_name,method);
}

//check metoda za operacije
void AddSynTree :: fill_table(string class_name,string method) const{


}

TypeTree* AddSynTree:: check(string class_name,string method) const{
	TypeTree* tip1 = _nodes[0]->check(class_name,method);
	TypeTree* tip2 = _nodes[1]->check(class_name,method);


	if((tip1->getType())==(tip2->getType()))
		if((tip1->getType())!="array" && ((tip1->getType())!="array"))
			return tip1;


	cerr<<"Promenljive nisu istog tipa, nije dozvoljena operacija sabiranja"<<endl;

	return NULL;

}

void SubSynTree :: fill_table(string class_name,string method) const{

}

TypeTree* SubSynTree:: check(string class_name,string method) const{
	TypeTree* tip1 = _nodes[0]->check(class_name,method);
	TypeTree* tip2 = _nodes[1]->check(class_name,method);

		if(tip1->getType()==tip2->getType())
			return tip1;


		cerr<<"Promenljive nisu istog tipa, nije dozvoljena operacija oduzimanja"<<endl;

		return NULL;

}

void MulSynTree :: fill_table(string class_name,string method) const{

}

TypeTree* MulSynTree:: check(string class_name,string method) const{
	TypeTree* tip1 = _nodes[0]->check(class_name,method);
		TypeTree* tip2 = _nodes[1]->check(class_name,method);

		if(tip1->getType()==tip2->getType())
			return tip1;


		cerr<<"Promenljive nisu istog tipa, nije dozvoljena operacija mnozenja"<<endl;

		return NULL;

}

void DivSynTree :: fill_table(string class_name,string method) const{

}

TypeTree* DivSynTree:: check(string class_name,string method) const{
		TypeTree* tip1 = _nodes[0]->check(class_name,method);
		TypeTree* tip2 = _nodes[1]->check(class_name,method);

		if(tip1->getType()==tip2->getType())
			return tip1;


		cerr<<"Promenljive nisu istog tipa, nije dozvoljena operacija deljenja"<<endl;

		return NULL;

}

void ModSynTree :: fill_table(string class_name,string method) const{

}

TypeTree* ModSynTree:: check(string class_name,string method) const{
	TypeTree* tip1 = _nodes[0]->check(class_name,method);
		TypeTree* tip2 = _nodes[1]->check(class_name,method);

		if(tip1->getType()==tip2->getType())
			return tip1;


		cerr<<"Promenljive nisu istog tipa, nije dozvoljena operacija delenja po modulu"<<endl;

		return NULL;
}

void LTSynTree :: fill_table(string class_name,string method) const{

}

TypeTree* LTSynTree:: check(string class_name,string method) const{
	TypeTree* tip1 = _nodes[0]->check(class_name,method);
	TypeTree* tip2 = _nodes[1]->check(class_name,method);

	if(tip1->getType()==tip2->getType())
		return tip1;


		cerr<<"Promenljive nisu istog tipa, nije dozvoljena operacija poredjena <"<<endl;

		return NULL;
}


void LTESynTree :: fill_table(string class_name,string method) const{

}

TypeTree* LTESynTree:: check(string class_name,string method) const{
	TypeTree* tip1 = _nodes[0]->check(class_name,method);
		TypeTree* tip2 = _nodes[1]->check(class_name,method);

		if(tip1->getType()==tip2->getType())
			return tip1;


		cerr<<"Promenljive nisu istog tipa, nije dozvoljena operacija poredjena =<"<<endl;

		return NULL;
}

void GTSynTree :: fill_table(string class_name,string method) const{

}

TypeTree* GTSynTree:: check(string class_name,string method) const{
	TypeTree* tip1 = _nodes[0]->check(class_name,method);
		TypeTree* tip2 = _nodes[1]->check(class_name,method);

		if(tip1->getType()==tip2->getType())
			return tip1;


		cerr<<"Promenljive nisu istog tipa, nije dozvoljena operacija poredjena >"<<endl;

		return NULL;
}

void GTESynTree :: fill_table(string class_name,string method) const{

}

TypeTree* GTESynTree:: check(string class_name,string method) const{
	TypeTree* tip1 = _nodes[0]->check(class_name,method);
		TypeTree* tip2 = _nodes[1]->check(class_name,method);

		if(tip1->getType()==tip2->getType())
			return tip1;


		cerr<<"Promenljive nisu istog tipa, nije dozvoljena operacija poredjena"<<endl;

		return NULL;
}

void AssignSynTree :: fill_table(string class_name,string method) const{
	_nodes[0]->fill_table(class_name,method);
	_nodes[1]->fill_table(class_name,method);
}

TypeTree* AssignSynTree:: check(string class_name,string method) const{
	TypeTree* tip1 = _nodes[0]->check(class_name,method);
		TypeTree* tip2 = _nodes[1]->check(class_name,method);

		if(tip1->getType()==tip2->getType())
			return tip1;


		cerr<<"Promenljive nisu istog tipa, nije dozvoljena operacija dodele "<<endl;

		return NULL;
}

void AndSynTree :: fill_table(string class_name,string method) const{

}

TypeTree* AndSynTree:: check(string class_name,string method) const{
	TypeTree* tip1 = _nodes[0]->check(class_name,method);
		TypeTree* tip2 = _nodes[1]->check(class_name,method);

		if(tip1->getType()==tip2->getType())
			return tip1;


		cerr<<"Promenljive nisu istog tipa"<<endl;

		return NULL;
}

void OrSynTree :: fill_table(string class_name,string method) const{

}

TypeTree* OrSynTree:: check(string class_name,string method) const{
	TypeTree* tip1 = _nodes[0]->check(class_name,method);
		TypeTree* tip2 = _nodes[1]->check(class_name,method);

		if(tip1->getType()==tip2->getType())
			return tip1;


		cerr<<"Promenljive nisu istog tipa"<<endl;

		return NULL;
}

void EqSynTree :: fill_table(string class_name,string method) const{

}

TypeTree* EqSynTree:: check(string class_name,string method) const{
	TypeTree* tip1 = _nodes[0]->check(class_name,method);
		TypeTree* tip2 = _nodes[1]->check(class_name,method);

		if(tip1->getType()==tip2->getType())
			return tip1;


		cerr<<"Promenljive nisu istog tipa, nije dozvoljena operacija == "<<endl;

		return NULL;
}

void NotEqSynTree :: fill_table(string class_name,string method) const{

}

TypeTree* NotEqSynTree:: check(string class_name,string method) const{
	TypeTree* tip1 = _nodes[0]->check(class_name,method);
		TypeTree* tip2 = _nodes[1]->check(class_name,method);

		if(tip1->getType()==tip2->getType())
			return tip1;


		cerr<<"Promenljive nisu istog tipa, nije dozvoljena operacija !="<<endl;

		return NULL;

}

//check opcija za kontrolu toka
void IfSynTree :: fill_table(string class_name,string method) const{

}

TypeTree* IfSynTree:: check(string class_name,string method) const{
	return NULL;
}

void IfThenSynTree :: fill_table(string class_name,string method) const{

}

TypeTree* IfThenSynTree:: check(string class_name,string method) const{
	return NULL;
}

void ForSynTree :: fill_table(string class_name,string method) const{

}

TypeTree* ForSynTree:: check(string class_name,string method) const{
	return NULL;
}

void WhileSynTree :: fill_table(string class_name,string method) const{

}

TypeTree* WhileSynTree :: check(string class_name,string method) const{
	return NULL;
}

void DoWhileSynTree :: fill_table(string class_name,string method) const{

}

TypeTree* DoWhileSynTree :: check(string class_name,string method) const{
	return NULL;
}


void ArrayAssignSynTree :: fill_table(string class_name,string method) const{

}

TypeTree* ArrayAssignSynTree :: check(string class_name,string method) const{
	return NULL;
}

void PrintST :: fill_table(string class_name,string method) const{

}

TypeTree* PrintST :: check(string class_name,string method) const{
return NULL;
}

void SynList :: fill_table(string class_name,string method) const{
	for(unsigned i=0;i<_nodes.size();i++)
		_nodes[i]->fill_table(class_name,method);
}

TypeTree* SynList:: check(string class_name,string method) const{
	return NULL;
}

void SynList:: addNext(SynTree* nod){
	_nodes.push_back(nod);
}


void ClassDeclaration:: fill_table(string class_name,string method) const{
	_name->fill_table(class_name,method);
	string name=_name->getClass();
	_nodes[0]->fill_table(name,method);
}

TypeTree* ClassDeclaration:: check(string class_name,string method) const{
	return NULL;
}


void Return :: fill_table(string class_name,string method) const{

}

TypeTree* Return:: check(string class_name,string method) const{
	return NULL;
}

void Dimension :: fill_table(string class_name,string method) const{

}

TypeTree* Dimension:: check(string class_name,string method) const{
	return NULL;
}

void ArrayAccess :: fill_table(string class_name,string method) const{

}

TypeTree* ArrayAccess:: check(string class_name,string method) const{
	return NULL;
}

void FieldAccess :: fill_table(string class_name,string method) const{

}

TypeTree* FieldAccess:: check(string class_name,string method) const{
	return NULL;
}


void MethodCall :: fill_table(string class_name,string method) const{

}

TypeTree* MethodCall:: check(string class_name,string method) const{
	return NULL;
}

MethodDeclaration:: MethodDeclaration(TypeTree* type,MethodDefinition* method,SynTree* expression){
	_modifier=NULL;
	_type=type;
	_method=method;
	_expression=expression;
}

MethodDeclaration:: MethodDeclaration(Modifier* modifier, TypeTree* type,MethodDefinition* method,SynTree* expression){
	_modifier=modifier;
	_type=type;
	_method=method;
	_expression=expression;
}

void MethodDeclaration :: fill_table(string class_name,string method) const{

	_method->fill_table(class_name,method);
	map<string,vector<Method>>:: iterator tmp= spisak_metoda.find(class_name);
		if(tmp == spisak_metoda.end()){
			cerr<<"Metoda nije definisana lepo"<<endl;
		}else{
			for(unsigned i=0;i<tmp->second.size();i++)
					if(tmp->second[i].getName()==_method->getMethod())
						tmp->second[i].addReturnType(_type);

		}
	if(_expression!=NULL)
		_expression->fill_table(class_name,_method->getMethod());
}

TypeTree* MethodDeclaration :: check(string class_name,string method) const{
	return NULL;
}


MethodDefinition :: MethodDefinition(string name){
	_name=name;
	_parameters=NULL;
}

MethodDefinition:: MethodDefinition(string name, SynList* parameters){
	_name=name;
	_parameters=parameters;
}

string MethodDefinition :: getMethod(){
	return _name;
}

void MethodDefinition :: fill_table(string class_name,string method) const{
	Method a = Method(_name);
	map<string,vector<Method>>:: iterator tmp= spisak_metoda.find(class_name);
	if(tmp == spisak_metoda.end()){
		vector<Method> t;
		t.push_back(a);
		spisak_metoda[class_name]=t;
	}else{
		for(unsigned i=0;i<tmp->second.size();i++)
				if(tmp->second[i].getName()==_name)
					cerr<<"Predefinisanje metoda"<<_name<<endl;
			tmp->second.push_back(a);
	}
	if(_parameters!=NULL)
		_parameters->fill_table(class_name,_name);


}

TypeTree* MethodDefinition :: check(string class_name,string method) const{
	return NULL;
}


ConstructorDeclaration :: ConstructorDeclaration(ConstructorDeclarator* con,SynTree* body){
	_modifier=NULL;
	_con=con;
	_body=body;
}

ConstructorDeclaration :: ConstructorDeclaration(Modifier* modifier,ConstructorDeclarator* con,SynTree* body){
	_modifier=modifier;
	_con=con;
	_body=body;
}

void ConstructorDeclaration :: fill_table(string class_name,string method) const{
		_con->fill_table(class_name,method);
		map<string,vector<Method>>:: iterator tmp= spisak_metoda.find(class_name);
			if(tmp == spisak_metoda.end()){
				cerr<<"Metoda nije definisana lepo"<<endl;
			}
		if(_body!=NULL)
			_body->fill_table(class_name,_con->getName());

}

TypeTree* ConstructorDeclaration :: check(string class_name,string method) const{
	return NULL;
}

ConstructorDeclarator :: ConstructorDeclarator(string name){
	_name=name;
	_parameters=NULL;
}

ConstructorDeclarator :: ConstructorDeclarator(string name,SynList* parameters){
	_name=name;
	_parameters=parameters;
}

string ConstructorDeclarator::getName(){
	return _name;
}

void ConstructorDeclarator :: fill_table(string class_name,string method) const{
	Method a = Method(_name);
		map<string,vector<Method>>:: iterator tmp= spisak_metoda.find(class_name);
		if(tmp == spisak_metoda.end()){
			vector<Method> t;
			t.push_back(a);
			spisak_metoda[class_name]=t;
		}else{
			tmp->second.push_back(a);
		}
		if(_parameters!=NULL)
			_parameters->fill_table(class_name,_name);

}

TypeTree* ConstructorDeclarator :: check(string class_name,string method) const{
	return NULL;
}

NewObject:: NewObject(TypeTree* type){
	_type=type;
	_args=NULL;
}

NewObject:: NewObject(TypeTree* type,SynList* args){
	_type=type;
	_args=args;
}

void NewObject :: fill_table(string class_name,string method) const{

}

TypeTree* NewObject :: check(string class_name,string method) const{
	return NULL;
}


void NewArray :: fill_table(string class_name,string method) const{

}

TypeTree* NewArray :: check(string class_name,string method) const{
	return NULL;
}


VariableDeclaration :: VariableDeclaration(TypeTree* type,SynList* list){
	_modifier=NULL;
	_type=type;
	_list=list;
}


VariableDeclaration :: VariableDeclaration(Modifier* modifier,TypeTree* type,SynList* list){
	_modifier=modifier;
	_type=type;
	_list=list;
}


void VariableDeclaration :: fill_table(string class_name,string method) const{
		map<string,HashT*>:: iterator tmp= stek_promenljivih.top().find(class_name);
		if(tmp == stek_promenljivih.top().end()){
			cerr<<"Klasa nije definisana"<<endl;
		}else{
			_list->fill_table(class_name,method);
			for(unsigned i=0;i<niz.size();i++)
				tmp->second->insert(niz[i],_type);
		}
		niz.erase(niz.begin(),niz.end());
}

TypeTree* VariableDeclaration :: check(string class_name,string method) const{
	return NULL;
}






