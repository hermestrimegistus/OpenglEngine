#pragma once
#include<array>
#include<iostream>
#include<assert.h>
#include<math.h>
using namespace std;
class Heap
{
 public:
  Heap(){}
  virtual ~Heap(){}
  virtual void PrintHeap() = 0;
  virtual int Left(int index) = 0;
  virtual int Right(int index) = 0;
  virtual int Parent(int index) = 0;
  virtual void BuildHeap() = 0;
  virtual bool TestHeap() = 0;
};
template<typename T,size_t Len>
class MaxHeap : public Heap
{
  size_t m_Len;
  size_t m_Size;
  array<T,Len> m_Array;
 public:
  MaxHeap(){
    m_Array = {};
  }
  MaxHeap(const initializer_list<T>& aList){
    int i(0);
    auto f = aList.begin();
    for(i;i<aList.size();++i){
      m_Array[i] = *f;
      ++f;
    }
  }
  template<typename T,size_t aLen>
  friend MaxHeap<T,aLen>* BuildMaxHeap(T(&)[aLen]);
  void PrintHeap()
  {
    std::cout<<"PrintHeap "<<"m_Size: "<<m_Size<<"m_Array.size"<<m_Array.size()<<"\n";
    assert(m_Size == m_Array.size()-1 && "Error in sizes");
    for(int i = 0;i<=m_Size;++i){
      std::cout<<m_Array[i]<<"\t";
    }
    std::cout<<"\n";
  }
  int Left(int index);
  int Right(int index);
  int Parent(int index);
  void MaxHeapify(int index);
  void BuildHeap();
  bool TestHeap();
  ~MaxHeap(){}
};
template<typename T,size_t Len>
bool MaxHeap<T,Len>::TestHeap()
{
  int i(floor(m_Size/1));
  for(i;i>0;--i){
    int par = Parent(i);
    if(m_Array[i] > m_Array[par]){
      std::cout<<"Test heap failed";
      std::cout<<"i :" <<i<<"val: "<<m_Array[i]<<"\n";
      std::cout<<"parent: "<<par<<"val : "<<m_Array[par]<<"\n";
      return false;
    }
  }
  return true;
}
template<typename T,size_t Len>
int MaxHeap<T,Len>::Left(int index)
{
  return (index << 1)+1;
}
template<typename T,size_t Len>
int MaxHeap<T,Len>::Right(int index)
{
  int r = ((index << 1) +2);
  //std::cout<<"Right : "<<r<<"\n";
  return r;
}
template<typename T,size_t Len>
int MaxHeap<T,Len>::Parent(int index)
{
  int x = index-1;
  int ret = floor(x/2);
  std::cout<<"Returning i "<<index<<" parent "<<ret<<"\n";
  return ret;
}
template<typename T,size_t Len>
void MaxHeap<T,Len>::MaxHeapify(int index)
{
  assert(index <= m_Size && "Index out of bound");
  T& iVal = m_Array[index];
  int left = Left(index);
  int right = Right(index);
  T& lVal = m_Array[left];
  T& rVal = m_Array[right];
  int largest = index;
  T& largestValue = m_Array[index];
  if(left <= m_Size && lVal > iVal){
    largest = left;
    largestValue = lVal;
  }
  //std::cout<<"mSize is "<<m_Size<<"\n";
  //std::cout<<"right is "<<right<<"\t"<<rVal<<"\n";
  //std::cout<<"left is "<<left<<"\t"<<lVal<<"\n";
  if(right <= m_Size && rVal > largestValue){
    largest = right;
  }
  //std::cout<<"largest is "<<largest<<"\n";
  if(largest != index){
    std::cout<<"Swapping "<<index <<" and "<<largest<<"\n";
    //R
    T& temp = m_Array[index];
    m_Array[index] = m_Array[largest];
    m_Array[largest] = temp;
    MaxHeapify(largest);
  }
  return;
}
template<typename T,size_t aLen>
MaxHeap<T,aLen>* BuildMaxHeap(T(&arr)[aLen]){
  MaxHeap<T,aLen>* h = new MaxHeap<T,aLen>();
  int i;
  //std::cout<<"aLen is "<<aLen<<"\n";
  for(i = 0;i<aLen;++i){
    h->m_Array[i] = arr[i];
    //std::cout<<"index "<<i<<" val: "<<arr[i]<<"\t";
  }
  h->m_Size = i-1;
  //std::cout<<"heap size is "<<i<<"\n";
  return h;
}
template<typename T,size_t aLen>
void MaxHeap<T,aLen>::BuildHeap()
{
  int mid = m_Size/2;
  int i = mid;
  std::cout<<"Mid is "<<i<<"\n";
  for(i;i>=0;i--){
    MaxHeapify(i);
  }
}
