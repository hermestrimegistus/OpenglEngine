#pragma once
#include<math.h>
#include<iostream>
template<typename T,size_t n>
class TwoStack
{
  T mArray[n];
  int head1;
  int head2;
  int mid;
  int mSize;
  public:
  TwoStack();
  ~TwoStack();
  void Push1(const T&);
  T Pop1();
  void Push2(const T&);
  T Pop2();
  void Print();
};

template<typename T,size_t n>
TwoStack<T,n>::TwoStack()
{
  head1 = 0;
  head2 = n-1;
  mid = floor(n>>1);
  mSize = n;
  for(int i = 0;i<mSize;++i){
    mArray[i] = T();
  }
}
template<typename T,size_t n>
TwoStack<T,n>::~TwoStack()
{
}
template<typename T,size_t n>
void TwoStack<T,n>::Push1(const T& t)
{
  if(head1 > head2){
    std::cout<<"Stack full\n";
    return;
  }
  if(head1 == mid+1){
  Push2(t);
  return;
  }
  if(head1 == -1) head1 = 0;
  mArray[head1] = t;
  head1++;
}
template<typename T,size_t n>
T TwoStack<T,n>::Pop1()
{
  if(head1 == -1){
    std::cout<<"Underflow\n";
    return T();
  }
  if(head1 > head2) head1--;
  return mArray[head1--];
}
template<typename T,size_t n>
void TwoStack<T,n>::Push2(const T& t)
{
  if(head2 < head1){
    std::cout<<"Stack full\n";
    return;
  }
  if(head2 == mid){
    Push1(t);
    return;
  }
  if(head2 == mid-1) head2 = mid;
  mArray[head2] = t;
  head2--;
}
template<typename T,size_t n>
T TwoStack<T,n>::Pop2()
{
  if(head2 == mSize){
    std::cout<<"Underflow\n";
    return T();
  }
  if(head2 < head1) head2++;
  return mArray[head2++];
}
template<typename T,size_t n>
void TwoStack<T,n>::Print()
{
  for(int i = 0;i<mSize;++i){
    std::cout<<i<<": "<<mArray[i]<<"\t";
  }
  std::cout<<"\n";
}
