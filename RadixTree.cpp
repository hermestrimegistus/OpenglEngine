#include<stdio.h>
#include<stdargs.h>
struct Node
{
  char Value[64];
  Node* left;
  Node* right;
  Node* parent;
  Node();
  ~Node();
};

Node::Node()
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
}
Radix::~Radix()
{
}
void Radix::Insert(const char* arg)
{
  Node* runner = root;
  Node* backer = 0;
  while(arg)
  {
    backer = runner;
    if(*arg == '0'){
      runner = runner->left;
    }
  }
}

int main()
{
  //How would you insert?
  Radix tree;
  tree.Insert("0100101");
  return 0;
}




