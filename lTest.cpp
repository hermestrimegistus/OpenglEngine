#include "LL.h"

int main()
{
  LList<int> intList;
  int a(10);
  intList.Insert(a,1);
  intList.Insert(20,2);
  intList.Insert(30,3);
  Node<int>* found = intList.Search(3);
  if(found){
    std::cout<<"Found key:" <<found->Key()<<" Data: "<<found->Data()<<"\n";
  }
  intList.Print();
  intList.Delete(3);
  intList.Delete(1);
  intList.Print();
  return 0;
}
