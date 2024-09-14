#include <iostream>
#include <vector>
using namespace std;

template<class S,auto op, auto e> struct segtree{
  int n;
  int size;
  vector<S> nodes;
  segtree():segtree(0){}
  segtree(int n){
    size = 1;
    while(size < n) size *= 2;
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
  S prod(int l,int r){
    l += size; r += size;
    S lb = e(), rb= e();
    while(l < r){
      if(l&1) lb = op(lb,nodes[l++]);
      if(r&1) rb = op(rb,nodes[--r]);
      l >>= 1;
      r >>= 1;
    }
    return op(rb,lb);
  }
};

int op(int a,int b){return a+b;}
int e(){return 0;}

int main(){
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  segtree<int,op,e> seg(n);
  for(int i=0;i<n-1;i++) if(s[i] != s[i+1]) seg.set(i+1,1);
  while(q--){
    int type;
    cin >> type;
    int l,r;
    cin >> l >> r;
    if(type == 1){
      seg.set(l-1,1-seg.get(l-1));
      seg.set(r,1-seg.get(r));
    }else{
      if(seg.prod(l,r) == (r-l)) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
  return 0;
}

