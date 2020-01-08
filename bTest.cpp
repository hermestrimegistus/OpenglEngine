#include "BSTint.h"
#include<stdio.h>
int main()
{
	Tree* t = new Tree();
	t->Insert(4);
	t->Insert(9);
	t->Insert(10);
	//t->Insert(2);
	t->Insert(19);
	//t->Insert(1);
	t->Insert(5);
	t->Insert(8);
	t->Insert(11);
	t->Insert(21);
	t->Insert(20);
    int k = 11;
	Node* l = t->LinearSearch(k);
	Node* s = t->Predecessor(l);
	if(l && s){
		fprintf(stdout,"Predecessor of %d is %d\n",k,s->key);
	}
	t->Inorder();
	delete t;
	return 0;
}
