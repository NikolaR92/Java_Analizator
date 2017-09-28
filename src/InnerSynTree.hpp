#ifndef __INNERSYNTREE_HPP__
#define __INNERSYNTREE_HPP__

#include "Syntree.hpp"


//Unutrasnje stablo
class InnerSynTree : public SynTree{
public:
	InnerSynTree(SynTree* a);
	InnerSynTree(SynTree* a,SynTree* b);
	InnerSynTree(SynTree* a,SynTree* b,SynTree* c);
	InnerSynTree(SynTree* a,SynTree* b,SynTree* c,SynTree* d);
	InnerSynTree(vector<SynTree*> a);
	~InnerSynTree();

protected:
	vector<SynTree*> _nodes;
private:
	InnerSynTree(const InnerSynTree& i);
	InnerSynTree& operator=(const InnerSynTree& i);
};


//Binarne operacije
class AddSynTree : public InnerSynTree{
public:
	AddSynTree(SynTree* left,SynTree* right)
	: InnerSynTree(left,right)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
};

class SubSynTree : public InnerSynTree{
public:
	SubSynTree(SynTree* left,SynTree* right)
	: InnerSynTree(left,right)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
};

class MulSynTree : public InnerSynTree{
public:
	MulSynTree(SynTree* left,SynTree* right)
	: InnerSynTree(left,right)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
};

class DivSynTree : public InnerSynTree{
public:
	DivSynTree(SynTree* left,SynTree* right)
	: InnerSynTree(left,right)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
};

class ModSynTree : public InnerSynTree{
public:
	ModSynTree(SynTree* left,SynTree* right)
	: InnerSynTree(left,right)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
};

class LTESynTree : public InnerSynTree{
public:
	LTESynTree(SynTree* left,SynTree* right)
	: InnerSynTree(left,right)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
};

class GTESynTree : public InnerSynTree{
public:
	GTESynTree(SynTree* left,SynTree* right)
	: InnerSynTree(left,right)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
};


class AndSynTree : public InnerSynTree{
public:
	AndSynTree(SynTree* left,SynTree* right)
	: InnerSynTree(left,right)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
};

class OrSynTree : public InnerSynTree{
public:
	OrSynTree(SynTree* left,SynTree* right)
	: InnerSynTree(left,right)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
};

//Kontrola toka

class IfThenSynTree : public InnerSynTree{
public:
	IfThenSynTree(SynTree* Condition, SynTree* ThenBlock, SynTree* ElseBlock)
	:InnerSynTree(Condition,ThenBlock,ElseBlock)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
};

class IfSynTree : public InnerSynTree{
public:
	IfSynTree(SynTree* Condition, SynTree* ThenBlock)
	:InnerSynTree(Condition,ThenBlock)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
};

class ForSynTree : public InnerSynTree{
public:
	ForSynTree(SynTree* Init, SynTree* Expr, SynTree* Incr, SynTree* Block)
	:InnerSynTree(Init,Expr,Incr,Block)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
};

class WhileSynTree : public InnerSynTree {
public:
	WhileSynTree(SynTree* condition, SynTree* body)
	:InnerSynTree(condition,body)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
};

class DoWhileSynTree : public InnerSynTree{
public:
	DoWhileSynTree(SynTree* body,SynTree* condition)
	:InnerSynTree(body,condition)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
};

//klase dodele
class AssignSynTree : public InnerSynTree{
public:
	AssignSynTree(VariableST* name,SynTree* expression )
	:InnerSynTree(expression),_name(name)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
private:
	VariableST* _name;
};

class ArrayAssignSynTree : public InnerSynTree{
public:
	ArrayAssignSynTree(VariableST* name,SynTree* num,SynTree* expr)
	:InnerSynTree(num,expr),_name(name)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
private:
	VariableST* _name;
};

class PrintST : public InnerSynTree{
public:
	PrintST(SynTree* expression)
	: InnerSynTree(expression)
	{}
	void fill_table(string class_name,int location) const;
	TypeTree* check() const;
};



#endif
