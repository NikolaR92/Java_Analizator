#include "Syntree.hpp"


stack<map<string,HashT*>> stek_promenljivih;
map<string, vector<Method>> spisak_metoda;
vector<string> niz;

SynTree:: ~SynTree(){

}

void ConstIntST :: fill_table(string class_name,string method) const{
	//cout<<_num<<endl;
}

TypeTree* ConstIntST :: check(string class_name,string method) const{
	return new IntType();
}

void ConstDoubleST :: fill_table(string class_name,string method) const{

}

TypeTree* ConstDoubleST :: check(string class_name,string method) const{
	return new DoubleType();
}


void ConstCharST :: fill_table(string class_name,string method) const{

}

TypeTree* ConstCharST:: check(string class_name,string method) const{
	return new CharType();
}

void ConstBooleanST :: fill_table(string class_name,string method) const{

}

TypeTree* ConstBooleanST :: check(string class_name,string method) const{
	return new BooleanType();
}

void ThisST :: fill_table(string class_name,string method) const{

}

TypeTree* ThisST :: check(string class_name,string method) const{
	return new ObjectType(class_name);
}

void SuperST :: fill_table(string class_name,string method) const{

}

TypeTree* SuperST :: check(string class_name,string method) const{
	return NULL;
}

void VariableST :: fill_table(string class_name,string method) const{
	niz.push_back(_name);
}

TypeTree* VariableST :: check(string class_name,string method) const{
	map<string,HashT*>:: iterator tmp= stek_promenljivih.top().find(class_name);
			if(tmp == stek_promenljivih.top().end()){
				cerr<<"Klasa nije definisana"<<endl;
			}else{
				TypeTree* tip= tmp->second->lookup(_name);
				return tip;
			}
	return NULL;
}


void Parameter :: fill_table(string class_name,string method) const{
	map<string,vector<Method>>:: iterator tmp= spisak_metoda.find(class_name);
		if(tmp == spisak_metoda.end()){
			cerr<<"Postoje parametri, nema metode: "<<method<<endl;
		}else{
			for(unsigned i=0;i<tmp->second.size();i++)
					if(tmp->second[i].getName()==_name){
						Type m = Type(_type,_name);
						tmp->second[i].addType(m);
					}

		}

}

TypeTree* Parameter :: check(string class_name,string method) const{

	map<string,HashT*>:: iterator tmp= stek_promenljivih.top().find(class_name);
				if(tmp == stek_promenljivih.top().end()){
					cerr<<"Klasa nije definisana"<<endl;
				}else{
					tmp->second->insert(_name,_type);
				}
	return NULL;
}

ClassDefinition:: ClassDefinition(string name){
	_modifier=NULL;
	_name=name;
	_extends="";
}

ClassDefinition:: ClassDefinition(string name,string extends){
	_modifier=NULL;
	_name=name;
	_extends=extends;
}

ClassDefinition:: ClassDefinition(Modifier* modifier,string name, string extends){
	_modifier=modifier;
	_name=name;
	_extends=extends;
}

ClassDefinition::ClassDefinition(Modifier* modifier, string name){
	_modifier=modifier;
	_name=name;
	_extends="";
}


void ClassDefinition :: fill_table(string class_name,string method) const{
	map<string,HashT*> tablica;
	tablica[_name]=new HashT();
	stek_promenljivih.push(tablica);
}

TypeTree* ClassDefinition :: check(string class_name,string method) const{
	return NULL;
}

string ClassDefinition:: getClass(){
	return _name;
}

void Package :: fill_table(string class_name,string method) const{

}

TypeTree* Package :: check(string class_name,string method) const{
	return NULL;
}

void Import :: fill_table(string class_name,string method) const{

}

TypeTree* Import :: check(string class_name,string method) const{
	return NULL;
}

void Modifier :: fill_table(string class_name,string method) const{

}

TypeTree* Modifier :: check(string class_name,string method) const{
	return NULL;
}



