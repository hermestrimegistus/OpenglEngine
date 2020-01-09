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

	void Inorder();
	void Inorder(Node*);
    void Preorder();
	void Preorder(Node*);
	void Postorder(Node*);

	void Transplant(Node* discard,Node* attach);
    void Transplant(int,int);
	bool Orphan(Node*);
	Node* LinearSearch(int);
};
void Tree::Delete(int _key)
{
  Node* d = LinearSearch(_key);
  Delete(d);
}
void Tree::Delete(Node* d)
{
  if(!d) return;
  if(!d->left){
    Transplant(d,d->right);
    d->right->parent = d->parent;
  }
  else if(!d->right)
  {
    Transplant(d,d->left);
    d->left->parent = d->parent;
  }
  else{
    //Find d's successor;
    Node* s = Successor(d);
    //Replace d's successort with it's right subtree;
    Transplant(s,s->right);//s is not reachable now;
    Transplant(d,s);
    s->right = d->right;
    s->left = d->left;
  }
  delete d;
}
void Tree::Transplant(int a,int b)
{
  Node* r = LinearSearch(a);
  Node* m = LinearSearch(b);
  Transplant(r,m);
}
void Tree::Transplant(Node* discard, Node* put)
{
  if(!discard){
    return;
  }
  if(discard == root){
    root = put;
  }
  else if(discard == discard->parent->left){
    discard->parent->left = put;
  }
  else
  {
    discard->parent->right = put;
  }
  if(put){
    put->parent = discard->parent;
  }
  /*if(put->parent && put->parent->left == put)
  {
    put->parent->left = 0;
  }
  else if(put->parent){
    put->parent->right = 0;
  }*/
}
Node* Tree::Successor(Node* p)
{
  if(!p) return 0;
  if(p->right)
    return Minimum(p->right);
  Node* y = p->parent;
  while(y && y->right == p){
    p = y;
    y = p->parent; 
  }
  return y;
}
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
	if(p->left){
		return Maximum(p->left);
	}
	Node* y = p->parent;
	while(y->left == p){
		p = y;
		y = p->parent;
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
void Tree::Preorder()
{
 Preorder(root);
 fprintf(stdout,"\n"); 
}
void Tree::Preorder(Node* p)
{
  if(p){
    fprintf(stdout,"%d ",p->key);
    Preorder(p->left);
    Preorder(p->right);
  }
}
