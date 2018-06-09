#include <string>
#include <vector>
#include "TypeTree.hpp"


class Type{
public:
	Type(TypeTree* type,string name)
	: _type(type),_name(name)
	{}
	TypeTree*  getType();
	string getName();
private:
	TypeTree* _type;
	string _name;
};


class Method {
public:
	Method(string name)
	: _name(name)
    {}
	void addType(Type t);
	void addReturnType(TypeTree* r);
	string getName();
private:
	vector<Type> _parametri;
	string _name;
	TypeTree* _returnType;
};

