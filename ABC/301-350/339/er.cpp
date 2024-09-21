#include <iostream>
#include <vector>
using namespace std;

template<class S, auto op, auto e> struct segtree{
  int n;
  int size;
  vector<S> nodes;
  segtree(int n):n(n){
    size = 1;
    while(size < n) size*=2;
    nodes.resize(2*size,0);
  }
  void update(int k){
    nodes[k] = op(nodes[2*k],nodes[2*k+1]);
  }
  void set(int p, S x){
    p += size;
    nodes[p] = x;
    while(p){
      update(p>>1);
      p >>= 1;
    }
  }
  S get(int p){
    return nodes[p+size];
  }
  S prod(int l, int r){
    S rb = e(), lb = e();
    l += size; r += size;
    while(l < r){
      if(l&1) lb = op(lb,nodes[l++]);
      if(r&1) rb = op(rb,nodes[--r]);
      l >>= 1;
      r >>= 1;
    }
    return op(rb,lb);
  }
  void show(){
    for(int i=size;i<size+10;i++) cout << nodes[i] << ' ';
    cout << endl;
  }
};

int op(int a, int b) {return max(a,b);}
int e(){return 0;}
int main(){
  int n,d;
  cin >> n >> d;
  const int M = 5e5+5;
  segtree<int,op,e> seg(M);
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    int l = max(0,a-d);
    int r = min(M,a+d);
    seg.set(a,seg.prod(l,r+1)+1);
    //seg.show();
  }
  int ans = seg.prod(0,M);
  cout << ans << endl;
}


  
  
