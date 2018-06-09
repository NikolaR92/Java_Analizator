#ifndef __INNERSYNTREE_HPP__
#define __INNERSYNTREE_HPP__

#include "Syntree.hpp"

extern stack<map<string,HashT*>> stek_promenljivih;
extern map<string,vector<Method>> spisak_metoda;
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


//Kontrola toka

class IfThenSynTree : public InnerSynTree{
public:
	IfThenSynTree(SynTree* Condition, SynTree* ThenBlock, SynTree* ElseBlock)
	:InnerSynTree(Condition,ThenBlock,ElseBlock)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class IfSynTree : public InnerSynTree{
public:
	IfSynTree(SynTree* Condition, SynTree* ThenBlock)
	:InnerSynTree(Condition,ThenBlock)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class ForSynTree : public InnerSynTree{
public:
	ForSynTree(SynTree* Init, SynTree* Expr, SynTree* Block)
	:InnerSynTree(Init,Expr,Block)
	{}
	ForSynTree(SynTree* Init, SynTree* Expr, SynTree* Incr, SynTree* Block)
	:InnerSynTree(Init,Expr,Incr,Block)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class WhileSynTree : public InnerSynTree {
public:
	WhileSynTree(SynTree* condition, SynTree* body)
	:InnerSynTree(condition,body)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class DoWhileSynTree : public InnerSynTree{
public:
	DoWhileSynTree(SynTree* body,SynTree* condition)
	:InnerSynTree(body,condition)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

//klase dodele
class AssignSynTree : public InnerSynTree{
public:
	AssignSynTree(SynTree* name,SynTree* expression )
	:InnerSynTree(name,expression)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;

};

class ArrayAssignSynTree : public InnerSynTree{
public:
	ArrayAssignSynTree(VariableST* name,SynTree* num,SynTree* expr)
	:InnerSynTree(num,expr),_name(name)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
private:
	VariableST* _name;
};

class PrintST : public InnerSynTree{
public:
	PrintST(SynTree* expression)
	: InnerSynTree(expression)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class SynList : public InnerSynTree{
public:
	SynList(SynTree* node)
	:InnerSynTree(node)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
	void addNext(SynTree* nod);
};


class ClassDeclaration : public InnerSynTree{
public:
	ClassDeclaration(ClassDefinition* name)
	:InnerSynTree(NULL),_name(name)
	{}
	ClassDeclaration(ClassDefinition* name,SynTree* body)
	:InnerSynTree(body),_name(name)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
private:
	ClassDefinition* _name;
};

class Return : public InnerSynTree{
public:
	Return(SynTree* exp)
	:InnerSynTree(exp)
	 {}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class Dimension : public InnerSynTree{
public:
	Dimension(SynTree* a)
	:InnerSynTree(a)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class ArrayAccess : public InnerSynTree{
public:
	ArrayAccess(string name, SynTree* exp)
	:InnerSynTree(exp),_name(name)
	 {}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
private:
	string _name;
};

class FieldAccess : public InnerSynTree{
public:
	FieldAccess(SynTree* a,SynTree* b)
	:InnerSynTree(a,b)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class MethodCall : public InnerSynTree{
public:
	MethodCall(SynTree* name)
	:InnerSynTree(name),_args(NULL)
	{}
	MethodCall(SynTree* name,SynList* args)
	:InnerSynTree(name),_args(args)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
private:
	SynList* _args;
};


class MethodDefinition : public SynTree{
public:
	MethodDefinition(string name);
	MethodDefinition(string name,SynList* parameters);

	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
	string getMethod();
private:
	string _name;
	SynList* _parameters;
};



class MethodDeclaration : public SynTree{
public:
	MethodDeclaration(TypeTree* type,MethodDefinition* method,SynTree* expression);
	MethodDeclaration(Modifier* modifier,TypeTree* type,MethodDefinition* method,SynTree* expression);

	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
private:
	Modifier* _modifier;
	TypeTree* _type;
	MethodDefinition* _method;
	SynTree* _expression;
};



class ConstructorDeclarator : public SynTree{
public:
	ConstructorDeclarator(string name);
	ConstructorDeclarator(string name,SynList* parameters);

	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
	string getName();
private:
	string _name;
	SynList* _parameters;
};



class ConstructorDeclaration : public SynTree{
public:
	ConstructorDeclaration(ConstructorDeclarator* con, SynTree* body);
	ConstructorDeclaration(Modifier* modifier,ConstructorDeclarator* con, SynTree* body);

	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;

private:
	Modifier* _modifier;
	ConstructorDeclarator* _con;
	SynTree* _body;
};


class NewObject : public SynTree{
public:
	NewObject(TypeTree* type);
	NewObject(TypeTree* type,SynList* args);

	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
private:
	TypeTree* _type;
	SynList* _args;
};

class NewArray : public SynTree{
public:
	NewArray(TypeTree* type,Dimension* d)
	:_type(type),_d(d)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
private:
	TypeTree* _type;
	Dimension* _d;
};


class VariableDeclaration : public SynTree{
public:
	VariableDeclaration(TypeTree* type,SynList* list);
	VariableDeclaration(Modifier* modifier,TypeTree* type,SynList* list);

	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
private:
	Modifier* _modifier;
	TypeTree* _type;
	SynList* _list;
};





#endif
