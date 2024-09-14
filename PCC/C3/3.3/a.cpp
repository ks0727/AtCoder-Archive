#include <iostream>
#include <vector>
using namespace std;

template<class S, auto op, auto e> struct segtree{
  int n,size;
  vector<S> node;
  segtree(int n):n(n){
    size = 1;
    while(size < n) size *= 2;
    node.resize(size*2);
  }
  void update(int k){
    node[k] = op(node[2*k],node[2*k+1]);
  }
  void set(int k, S x){
    k += size;
    node[k] = x;
    while(k){
      update(k>>1);
      k>>=1;
    }
  }
  void get(int k){
    return node[k+size];
  }
  S prod(int l, int r){
    S lb = e(), rb =e();
    l += size; r += size;
    while(l < r){
      if(l&1) lb = op(lb,node[l++]);
      if(r&1) rb = op(rb,node[--r]);
      l >>= 1;
      r >>= 1;
    }
    return op(lb,rb);
  }
};
int op(int a,int b){return max(a,b);}
int e(){return 0;}

int c[3<<17];

int main(){
  int n;
  cin >> n;
  segtree<int,op,e> seg(n);
  for(int i=0;i<n;i++){
    int c;
    cin >> c;
    seg.set(c-1,seg.prod(0,c)+1);
  }
  cout << n - seg.prod(0,n) << endl;

  return 0;
}

