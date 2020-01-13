#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
enum Color
{
  RED,
  BLACK
};
class RBTree;
class Node
{
  friend class RBTree;
  Node* left;
  Node* right;
  Node* parent;
  Color color;
  int value;
  public:
  Node(Color c);
  Node();
  ~Node();
  int GetValue();
  Color GetColor();
};
Node::Node(Color c):color(c),left(0),right(0),parent(0)
{
}
Node::Node():left(0),right(0),parent(0),color(RED)
{
}
Node::~Node()
{
}
/* Root is red, leaf is black. If node is red both children are black.
   For each node, all path from node to descendant leaves contain same #of black nodes 
*/
class RBTree
{
  Node* root;

  //Balancing methods
  void Transplant(Node* discard, Node* attach);
  public:
  RBTree();
  ~RBTree();
  
  //Interfaces
  void Insert(int _key);
  void Delete(int _key);
  
  Node* Maximum(Node* p); 
  Node* Minimum(Node* p);

  Node* Search(int _key);
  
  Node* Successor(Node* p);
  Node* Predecessor(Node* p);

  void Delete(Node* p);
  
  void InorderPrint();
  void InorderPrint(Node* p);
  void PostorderDelete(Node* p);
};
void RBTree::PostorderDelete(Node* p)
{
  if(p){
    PostorderDelete(p->left);
    PostorderDelete(p->right);
    delete p;
  }
}
void RBTree::InorderPrint(Node* p)
{
  if(p){
    InorderPrint(p->left);
    fprintf(stdout,"%d\t",p->value);
    InorderPrint(p->right);
  }
}
void RBTree::InorderPrint()
{
  InorderPrint(root);
  fprintf(stdout,"\n");
}
void RBTree::Insert(int k)
{
  //Root is black
  if(!root){
    root = new Node(BLACK);
    root->value = k;
    return;
  }
  Node* runner = root;
  Node* backer = 0;
  while(runner){
  backer = runner;
  if(k <= runner->value){
    runner = backer->left;
    if(!runner){
      runner = new Node();
      runner->value = k;
      backer->left = runner;
      runner->parent = backer;
      break;
    }
  }
  else{
    runner = backer->right;
    if(!runner){
      runner = new Node();
      runner->value = k;
      backer->right = runner;
      runner->parent = backer;
      break;
    }
  }
  }
}

RBTree::RBTree():root(0)
{
}
RBTree::~RBTree()
{
  PostorderDelete(root);
}
int main()
{
  time_t t;
  time(&t);
  fprintf(stdout,"Time: %ld\n",t);
  int i = 0;
  int k;
  struct timespec tv;
  while(i < 10){
    sleep(1.3);
    clock_gettime(CLOCK_REALTIME,&tv);
    srand(tv.tv_sec);
    k = random();
    fprintf(stdout,"%d\n",k); 
    ++i;
  }
  RBTree rbtree;
  rbtree.Insert(5);
  rbtree.Insert(9);
  rbtree.Insert(0);
  rbtree.Insert(1);
  rbtree.Insert(2);
  rbtree.Insert(3);
  rbtree.Insert(4);
  rbtree.InorderPrint();
}
