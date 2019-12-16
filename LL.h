#pragma once
#include<iostream>
//SSH check
template<typename T>
class LList;
template<typename T>
class Node
{
  int key;
  T data;
  Node* next;
  Node* prev;
  public:
  int Key(){return key;}
  T& Data(){return data;}
  Node(){}
  Node(T _data,int _key){
    data = _data;
    key = _key;
  }
  ~Node(){}
  friend class LList<T>;
};
template<typename T>
class LList
{
  Node<T>* start;
  public:
  LList();
  ~LList();
  void Print();
  void Insert(const T&, int key);
  void Delete(int key);
  Node<T>* Search(int );
};
template<typename T>
Node<T>* LList<T>::Search(int key)
{
  Node<T>* p = start;
  while(p != nullptr){
    if(key == p->key)
      return p;
    p=p->next;
  }
  return nullptr;
}
template<typename T>
LList<T>::~LList()
{
  Node<T>* p = start;
  Node<T>* t = nullptr;
  while(p != nullptr){
   t = p->next;
   delete p;
   p = t;
  }
}
template<typename T>
LList<T>::LList()
{
  start = nullptr;
}
template<typename T>
void LList<T>::Insert(const T& _data,int key)
{
  Node<T>* n = new Node<T>(_data,key);//do custom allocator
  Node<T>* runner = start;
  if(!start){
    start = n;
    return;
  }
  start = n;
  n->next = runner;
  runner->prev = n;
}
template<typename T>
void LList<T>::Delete(int key)
{
  Node<T>* found = Search(key);
  if(found)
  {
    if(found->prev == NULL)
    {
      start = found->next;
      if(start)
      {
        start->prev = NULL;
      }
    }
    else
    {
      if(found->next)
      {
	found->next->prev = found->prev;
      }
      found->prev->next = found->next;
    }
    delete found;
  }
}
template<typename T>
void LList<T>::Print()
{
  Node<T>* p = start;
  while(p!=nullptr)
  {
    std::cout<<p->data<<"\t";
    p=p->next;
  }
  std::cout<<"\n";
}
