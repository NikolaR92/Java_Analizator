#include "SymbolTable.hpp"


Bucket :: ~Bucket(){

}

//Bucket* Bucket

void Bucket :: operator= (const Bucket& b){
  _key=b._key;
  _binding=b._binding;
  _next=b._next;
}

bool Bucket :: operator!=(const Bucket& b){
	if(_key!=b._key)
		return true;
	return false;
}


string Bucket :: getKey(){
	return _key;
}

TypeTree* Bucket :: getBinding(){
	return _binding;
}

Bucket* Bucket :: getNext(){
	return _next;
}

int HashT :: hash(string s){
	int h=0;
	for(unsigned i=0;i<s.length();i++)
		h=h*65599+s[i];

	return h;
}

void HashT :: insert(string s,TypeTree* binding){
	int index=hash(s)%SIZE;
	table[index]=new Bucket(s,binding,table[index]);
}

TypeTree* HashT :: lookup(string s){
	int index=hash(s)%SIZE;
	for(Bucket* binding=table[index];binding!=NULL;binding=binding->getNext())
		if(s==binding->getKey())
			return binding->getBinding();
	return NULL;
}

void HashT :: pop(string s){
	int index=hash(s)%SIZE;
	table[index]=table[index]->getNext();
}
