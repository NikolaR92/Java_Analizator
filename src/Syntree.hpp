#ifndef __SYNTREE_HPP__
#define __SYNTREE_HPP__

#include <string>
#include <vector>
#include "TypeTree.hpp"
#include "SymbolTable.hpp"
#include <iostream>
#include <stack>
#include <map>
#include "Method.hpp"

extern stack<map<string,HashT*>> stek_promenljivih;
extern map<string, vector<Method>> spisak_metoda;
extern vector<string> niz;

using namespace std;




class SynTree{
public:
	virtual ~SynTree();
	//funkcija fill table sluzi za popunjavanje vektora, sa svim mogucim klasama koje su nam potrebe za pokretanje
	 // class_name sluzi za naziv klase, location da li se promenljiva nalazi u klasi ili metodi.
	virtual void fill_table(string class_name,string method) const=0;
	virtual TypeTree* check(string class_name,string method) const=0;
};

//Cvor za konstantu tipa int
class ConstIntST: public SynTree{
public:
	ConstIntST(int num)
	:_num(num)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
private:
	int _num;
};

//Cvor za konstantu tipa float
class ConstDoubleST : public SynTree{
public:
	ConstDoubleST(double num)
	:_num(num)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
private:
	float _num;
};

//Cvor za konstantu tipa char
class ConstCharST : public SynTree{
public:
	ConstCharST(char c)
	:_c(c)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
private:
	char _c;
};

class ConstBooleanST : public SynTree{
public:
	ConstBooleanST(string b)
	:_b(b)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
private:
	string _b;
};

class ThisST : public SynTree{
public:
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class SuperST : public SynTree{
public:
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

//Cvor za promenljive
class VariableST : public SynTree{
public:
	VariableST(string s)
	: _name(s)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
private:
	string _name;
};


class Parameter : public SynTree{
public:
	Parameter(TypeTree* type,string name)
	:_type(type),_name(name)
	{}

	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
private:
	TypeTree* _type;
	string _name;
};

class Package : public SynTree{
public:
	Package(string name)
	:_name(name)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
private:
	string _name;
};

class Import : public SynTree{
public:
	Import(string location)
	:_location(location)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
private:
	string _location;
};

class Modifier : public SynTree{
public:
	Modifier(string range)
	:_range(range)
	{}

	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
private:
	string _range;
};

class ClassDefinition : public SynTree{
public:
	ClassDefinition(Modifier*, string name);
	ClassDefinition(Modifier* modifier,string name,string extends);
	ClassDefinition(string name);
	ClassDefinition(string name,string extends);


	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
	string getClass();
private:
	Modifier* _modifier;
	string _name;
	string _extends;
};





#endif
