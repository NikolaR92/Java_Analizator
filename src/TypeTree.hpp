#ifndef __TYPETREE_HPP__
#define __TYPETREE_HPP__ 1

#include <string>

using namespace std;


class TypeTree{
public:
	TypeTree(string modifier)
	:_modifier(modifier)
	{} 
	~TypeTree();
	virtual string getType() const=0;
	string getModifier() const;
protected:
	string _modifier;
};

class IntType : public TypeTree{
public:
	IntType(string modifier)
	:TypeTree(modifier)
	{}
	string getType() const;
};

class DoubleType : public TypeTree{
public: 
	DoubleType(string modifier)
	:TypeTree(modifier)
	{}
	string getType() const;
};

class CharType : public TypeTree{
public:
	CharType(string modifier)
	:TypeTree(modifier)
	{}
	string getType() const;
};

class ArrayType : public TypeTree{
public:
	ArrayType(string modifier,TypeTree* tip,int size)
	:TypeTree(modifier),_tip(tip),_size(size)
	{}
	string getType() const;
	TypeTree* getTip();
	int getSize();
private:
	TypeTree* _tip;
	int _size;
};


//treba proveriti sta dodati u tip objekat, da li samo definiciju klase ili da se doda cela klasa.
class ObjectType : public TypeTree{
public:
	ObjectType(string modifier,string name)
	: TypeTree(modifier),_name(name)
	{}
	string getType() const;
private:
	string _name;
};

class BooleanType : public TypeTree{
public:
	BooleanType(string modifier)
	:TypeTree(modifier)
	{}
	string getType() const;
};

#endif
