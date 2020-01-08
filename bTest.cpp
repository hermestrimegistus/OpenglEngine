#include "BSTint.h"
#include<stdio.h>
int main()
{
	Tree* t = new Tree();
	t->Insert(4);
	t->Insert(9);
	t->Insert(10);
	t->Insert(2);
	t->Insert(19);
	fprintf(stdout,"Maximum %d\n",t->Minimum(t->root)->key);
	Node* l = t->LinearSearch(4);
	Node* s = t->Predecessor(l);
	if(l && s){
		fprintf(stdout,"Predecessor is %d\n",s->key);
	}
	t->Inorder();
	delete t;
	return 0;
}
