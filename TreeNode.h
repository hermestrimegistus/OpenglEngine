#include<limits.h>
struct Node
{
	int key;
	Node* left;
	Node* right;
	Node* parent;
	Node();
	Node(int _key);
	Node(const Node&);
	Node operator=(const Node&);
	~Node();
};

Node::Node():left(0),right(0),parent(0),key(INT_MAX)
{
}
#define CDEL(x){\
	if(x) delete x;\
}

Node::~Node()
{
	CDEL(left);
	CDEL(right);
	CDEL(parent);
}
Node::Node(int _key):key(_key),
	right(0),left(0)
{
}
Node::Node(const Node& a)
{
	left = a.left;
	right = a.right;
	parent = a.parent;
	key = a.key;
}
Node Node::operator=(const Node& a)
{
	Node p(a);
	return p;
}
