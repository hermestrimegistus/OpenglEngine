#include "TreeNode.h"
#include<stdio.h>


class Tree
{
	public:
	Node* root;
	Tree();
	~Tree();

	void Insert(int _key);
	Node* Maximum(Node*);

	Node* Minimum(Node*);

	Node* Predecessor(Node*);

	Node* Successor(Node*);

	
	void Delete(int _key);
	void Delete(Node*);

	void Inorder(Node*);
	void Preorder(Node*);
	void Postorder(Node*);

	void Transplant(Node* discard,Node* attach);
	void Inorder();
	bool Orphan(Node*);
	Node* LinearSearch(int);
};
bool Tree::Orphan(Node* p)
{
	if(p)
	return !p->left && !p->right;
	return true;
}
Node* Tree::LinearSearch(int k)
{
	Node* runner = root;
	while(runner){
        if(k == runner->key)
          return runner;
		else if(k <= runner->key){
			runner = runner->left;
		}
		else
			runner = runner->right;
	}
	return 0;
}
Node* Tree::Predecessor(Node* p)
{
	if(p == root){
		return 0;
	}
	//Predecessor lies on left sub-tree
	Node* runner = p;
	Node* rightBranch = 0;
	if(runner->left){
		return Minimum(runner->left);
	}
	Node* y = runner->parent;
	while(y->left == runner){
		runner = y;
		y = runner->parent;
	}
	return y;
}
Node* Tree::Minimum(Node* p)
{
	Node* runner = p;
	Node* backer = 0;
	while(runner){
		backer = runner;
		runner = runner->left;
	}
	return backer;
}
Node* Tree::Maximum(Node* p)
{
	Node* runner = p;
	Node* backer = 0;
	while(runner){
		backer = runner;
		runner=runner->right;
	}
	return backer;
}
Tree::Tree():root(0)
{
}
Tree::~Tree()
{
}
void Tree::Insert(int k)
{
	if(!root){
		root = new Node(k);
		return;
	}
	Node* runner = root;
	Node* backer = 0;
	while(runner){
		backer = runner;
		if(k <= runner->key){
			runner = runner->left;
		}
		else
			runner = runner->right;
	}
	Node* t = new Node(k);
	t->parent = backer;
	if(k <= backer->key)
		backer->left = t;
	else
		backer->right = t;
}
void Tree::Inorder(Node* t)
{
	if(t){
		Inorder(t->left);
		fprintf(stdout,"%d \t",t->key);
		Inorder(t->right);
	}
}
void Tree::Inorder()
{
	Inorder(root);
	fprintf(stdout,"\n");
}
