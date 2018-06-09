#ifndef __SYMBOLTABLE_HPP_
#define __SYMBOLTABLE_HPP_


//ideja je da imamo mapu <ime_klase, Hash_t> tj za svaku klasu da imamo posebnu tablicu simbola.
//Prema toj mapi da pravimo sve ostalo.
#include <string>
#include <stack>
#include <map>
#include "TypeTree.hpp"

using namespace std;



class Bucket {
public:
	Bucket(string key, TypeTree* binding, Bucket* next)
	:_key(key),_binding(binding),_next(next)
   {}
	string getKey();
	TypeTree* getBinding();
	Bucket* getNext();
	~Bucket();
	void operator=(const Bucket& b );
	bool operator!=(const Bucket& b);
private:
	string _key;
	TypeTree* _binding;
	Bucket* _next;
};

class HashT{
public:
	static const int SIZE = 256;
	Bucket* table[SIZE];

	void insert(string s,TypeTree* binding);
	TypeTree* lookup(string s);
	void pop(string s);
private:
		int hash(string s);
};



#endif
