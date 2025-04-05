#include <iostream>
#include<vector>
using namespace std;

template<class T> struct BIT{
  int n;
  vector<T> tree;
  BIT(int n): n(n), tree(n+1, T{}){}
  
  void add(int i, T x){
    while(i <= n){
      tree[i] += x;
      i += i & (-i);
    }
  }
  
  T sum(int i){
    T s = 0;
    while( i > 0) {
      s += tree[i];
      i -= i & (-i);
    }
  }
};

