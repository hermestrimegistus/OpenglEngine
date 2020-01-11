#include<stdio.h>
#include<string.h>
struct Node
{
  int index;
  char Value[64];
  Node* left;
  Node* right;
  Node* parent;
  Node();
  ~Node();
};

Node::Node():left(0),right(0),parent(0),index(0)
{
}

Node::~Node()
{
}
struct Radix
{
  Node* root;
  int m_val;
  Radix();
  ~Radix();
  void Insert(const char* arg);
  void Preorder();
  void Preorder(Node* p);
  void PostOrderDelete(Node*);
};

Radix::Radix()
{
  root = new Node();
  strcpy(root->Value,"root");
}
void Radix::Preorder(Node* p)
{
  if(p){
    fprintf(stdout,"%s\t",p->Value);
    Preorder(p->left);
    Preorder(p->right);
  }
}
void Radix::Preorder()
{
  Preorder(root);
  fprintf(stdout,"\n");
}
void Radix::PostOrderDelete(Node* p)
{
  if(p){
    PostOrderDelete(p->left);
    PostOrderDelete(p->right);
    delete p;
  }
}
Radix::~Radix()
{
  PostOrderDelete(root);
}
void Radix::Insert(const char* arg)
{
  Node* runner = root;
  Node* backer = 0;
  char buffer[64];
  memset(buffer,0,64);
  int i(0);
  const char* p = arg;
  while(*p != '\0')
  {
    backer = runner;
    if(*p == '0'){
      runner = runner->left;
      if(!runner){
        Node* t = new Node();
        backer->left = t;
        t->parent = backer;
        t->Value[t->index++] = *p;
        runner = t;
      }
    }
    else{
      runner = runner->right;
      if(!runner){
        Node* t = new Node();
        backer->right = t;
        t->parent = backer;
        t->Value[t->index++] = *p;
        runner = t;
      }
    }
    p++;
  }
  strcpy(runner->Value,arg);
}

int main()
{
  //How would you insert?
  Radix tree;
  tree.Insert("0100101");
  tree.Preorder();
  return 0;
}




