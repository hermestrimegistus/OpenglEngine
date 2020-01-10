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
};

Radix::Radix()
{
  root = new Node();
  strcpy(root->Value,"Dummy");
}
Radix::~Radix()
{
}
void Radix::Insert(const char* arg)
{
  Node* runner = root;
  Node* backer = 0;
  char buffer[64];
  memset(buffer,0,64);
  int i(0);
  const char* p = arg;
  char k;
  while(p)
  {
    k = *p;
    backer = runner;
    if(*p == '0'){
      runner = runner->left;
      if(!runner){
        Node* t = new Node();
        backer->left = t;
        t->parent = backer;
        t->Value[t->index++] = k;
      }
    }
    else{
      runner = runner->right;
      if(!runner){
        Node* t = new Node();
        backer->right = t;
        t->parent = backer;
        t->Value[t->index++] = k;
      }
    }
    p++;
  }
  if(backer && k == '0'){
    backer->left = new Node();
    strcpy(backer->left->Value,arg);
  }
  else if(backer && k == '1'){
    backer->right = new Node();
    strcpy(backer->right->Value,arg);
  }
}

int main()
{
  //How would you insert?
  Radix tree;
  tree.Insert("0100101");
  return 0;
}




