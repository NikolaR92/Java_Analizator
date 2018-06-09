
//TODO Treba dodati odraditi cpp deo za ovaj hpp

//Stablo za izraze
class ExpressionAST{
public:
	ExpressionAST(SynTree* a);
	ExpressionAST(SynTree* a,SynTree* b);
	
	~ExpressionAST();

protected:
	SynTree* _left;
	SynTree* _right;
private:
	ExpressionAST(const ExpressionAST& i);
	ExpressionAST& operator=(const ExpressionAST& i);
};


//Unarne operacije
class PrefixAdd : public ExpressionAST{
public:
	PrefixAdd(SynTree* a)
	:ExpressionAST(a)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class PrefixSub : public ExpressionAST{
public:
	PrefixSub(SynTree* a)
	:ExpressionAST(a)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class PostfixAdd : public ExpressionAST{
public:
	PostfixAdd(SynTree* a)
	:ExpressionAST(a)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class PostfixSub : public ExpressionAST{
public:
	PostfixSub(SynTree* a)
	:ExpressionAST(a)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};


//Binarne operacije
class AddSynTree : public ExpressionAST{
public:
	AddSynTree(SynTree* left,SynTree* right)
	: ExpressionAST(left,right)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class SubSynTree : public ExpressionAST{
public:
	SubSynTree(SynTree* left,SynTree* right)
	: ExpressionAST(left,right)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class MulSynTree : public ExpressionAST{
public:
	MulSynTree(SynTree* left,SynTree* right)
	: ExpressionAST(left,right)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class DivSynTree : public ExpressionAST{
public:
	DivSynTree(SynTree* left,SynTree* right)
	: ExpressionAST(left,right)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class ModSynTree : public ExpressionAST{
public:
	ModSynTree(SynTree* left,SynTree* right)
	: ExpressionAST(left,right)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class LTSynTree : public ExpressionAST{
public:
	LTSynTree(SynTree* left,SynTree* right)
	: ExpressionAST(left,right)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};


class LTESynTree : public ExpressionAST{
public:
	LTESynTree(SynTree* left,SynTree* right)
	: ExpressionAST(left,right)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class GTSynTree : public ExpressionAST{
public:
	GTSynTree(SynTree* left,SynTree* right)
	: ExpressionAST(left,right)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};


class GTESynTree : public ExpressionAST{
public:
	GTESynTree(SynTree* left,SynTree* right)
	: ExpressionAST(left,right)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};


class AndSynTree : public ExpressionAST{
public:
	AndSynTree(SynTree* left,SynTree* right)
	: ExpressionAST(left,right)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class OrSynTree : public ExpressionAST{
public:
	OrSynTree(SynTree* left,SynTree* right)
	: ExpressionAST(left,right)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class EqSynTree : public ExpressionAST{
public:
	EqSynTree(SynTree* left,SynTree* right)
	:ExpressionAST(left,right)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};

class NotEqSynTree : public ExpressionAST{
public:
	NotEqSynTree(SynTree* left,SynTree* right)
	:ExpressionAST(left,right)
	{}
	void fill_table(string class_name,string method) const;
	TypeTree* check(string class_name,string method) const;
};
