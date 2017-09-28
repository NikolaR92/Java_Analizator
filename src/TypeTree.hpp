#ifndef __TYPETREE_HPP__
#define __TYPETREE_HPP__ 1

#include <string>

using namespace std;

class TypeTree{
public:
	~TypeTree();
	virtual string getType() const=0;
};

class IntType : public TypeTree{
public:
	string getType() const;
};

class FloatType : public TypeTree{
public:
	string getType() const;
};

class CharType : public TypeTree{
public:
	string getType() const;
};

class ArrayType : public TypeTree{
public:
	ArrayType(TypeTree* tip,int size)
	:_tip(tip),_size(size)
	{}
	string getType() const;
	TypeTree* getTip();
	int getSize();
private:
	TypeTree* _tip;
	int _size;
};

class MatrixType : public TypeTree{
public:
	MatrixType(TypeTree* tip, int size1, int size2)
	:_tip(tip),_size1(size1),_size2(size2)
	{}
	string getType() const;
	TypeTree* getTip();
	int getSize1();
	int getSize2();
private:
	TypeTree* _tip;
	int _size1;
	int _size2;
};

class ObjectType : public TypeTree{
public:
	ObjectType(string name)
	: _name(name)
	{}
	string getType() const;
private:
	string _name;
};

class BooleanType : public TypeTree{
public:
	string getType() const;
};

#endif
