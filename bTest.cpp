#include "BSTint.h"
#include<stdio.h>
int main()
{
	Tree* t = new Tree();
	t->Insert(4);
	t->Insert(5);
	t->Insert(8);
	t->Insert(9);
	t->Insert(2);
	t->Insert(1);
    t->Insert(3);
	t->Insert(10);
	t->Insert(11);
	t->Insert(19);
	t->Insert(21);
	t->Insert(20);
    t->Insert(15);
    t->Insert(18);
    t->Insert(17);
    t->Insert(14);
    t->Insert(24);
    t->Insert(23);
    t->Insert(22);
    t->Insert(30);
    t->Insert(25);
    t->Insert(26);
    t->Insert(27);
    int k = 14;
	Node* l = t->LinearSearch(k);
	Node* s = t->Predecessor(l);
	if(l && s){
		fprintf(stdout,"Predecessor of %d is %d\n",k,s->key);
	}
	t->Inorder();
    t->Delete(30);
    t->Inorder();
    t->Preorder();
	delete t;
	return 0;
}
