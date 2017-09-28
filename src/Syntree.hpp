#ifndef __SYNTREE_HPP__
#define __SYNTREE_HPP__

#include <string>
#include <vector>
#include "TypeTree.hpp"
#include "SymbolTable.hpp"

using namespace std;


class SynTree{
public:
	virtual ~SynTree();
	//funkcija fill table sluzi za popunjavanje vektora, sa svim mogucim klasama koje su nam potrebe za pokretanje
	 // class_name sluzi za naziv klase, location da li se promenljiva nalazi u klasi ili metodi.
	virtual void fill_table(string class_name,int location) const=0;
	virtual TypeTree* check() const=0;
};

//Cvor za konstantu tipa int
class ConstIntST: public SynTree{
public:
	ConstIntST(int num)
	:_num(num)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
private:
	int _num;
};

//Cvor za konstantu tipa float
class ConstFloatST : public SynTree{
public:
	ConstFloatST(float num)
	:_num(num)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
private:
	float _num;
};

//Cvor za konstantu tipa char
class ConstCharST : public SynTree{
public:
	ConstCharST(char c)
	:_c(c)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
private:
	char _c;
};

class ConstBooleanST : public SynTree{
public:
	ConstBooleanST(bool b)
	:_b(b)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
private:
	bool _b;
};

//Cvor za promenljive
class VariableST : public SynTree{
public:
	VariableST(string s)
	: _name(s)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
private:
	string _name;
};

class VariableDeclaration : public SynTree{
public:
	VariableDeclaration(TypeTree* type, VariableST* name)
	:_type(type),_name(name)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
private:
	TypeTree* _type;
	VariableST* _name;
};


class MethodDeclaration : public SynTree{
public:
	MethodDeclaration(TypeTree* type, string method_name,vector<VariableDeclaration*> args,
						SynTree* expression)
	:_type(type),_method_name(method_name),_args(args),_expression(expression)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
private:
	TypeTree* _type;
	string _method_name;
	vector<VariableDeclaration*> _args;
	SynTree* _expression;
};

class ClassDeclaration : public SynTree{
public:
	ClassDeclaration(string name,SynTree* body)
	: _name(name),_body(body)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
private:
	string _name;
	SynTree* _body;
};

class ClassDeclarationExtends : public SynTree{
public:
	ClassDeclarationExtends(string name,string extend_name,SynTree* body)
	:_name(name),_extend_name(extend_name),_body(body)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
private:
	string _name,_extend_name;
	SynTree* _body;

};

class Package : public SynTree{
public:
	Package(string name)
	:_name(name)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
private:
	string _name;
};

class Import : public SynTree{
public:
	Import(string location)
	:_location(location)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
private:
	string _location;
};

#endif
