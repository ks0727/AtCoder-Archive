#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
template<class S, auto op, auto e> struct segtree{
  int n;
  int size;
  vector<int> node;
  segtree():segtree(0){}
  segtree(int n):n(0){
    size = 1;
    while(n)n>>=1,size*=2;
    size *= 2;
    node.resize(2*size,S(1LL<<31)-1);
  }

  void update(int x){
    node[x] = op(node[2*x],node[2*x+1]);
  }

  void set(int p, S x){
    p += size;
    node[p] = x;
    while(p){
      update(p>>1);
      p >>= 1;
    }
  }

  S get(int p) const{
    return node[p+size];
  }

  S prod(int l, int r){
    S lb = e(), rb = e();
    l += size; r += size;
    while(l < r){
      if(l & 1) lb = op(lb,node[l++]);
      if(r & 1) rb = op(rb,node[--r]);
      l >>= 1;
      r >>= 1;
    }
    return op(lb,rb);
  }
  void print(){
    for(int i=0;i<size;i++) cout << node[i] << ' '; cout << endl;
  }
};
    
ll op(ll a,ll b){
  return min(a,b);
}
ll e(){return 1e18;}

int main(){
  int n,q;
  cin >> n >> q;
  segtree<ll,op,e> seg(n);
  while(q--){
    int type;
    cin >> type;
    int l,r;
    cin >> l >> r;
    if(type ==0){
      seg.set(l,r);
    }else if(type == 1){
      int x = seg.prod(l,r+1);
      cout << x << '\n';
    }
  }
  return 0;
}

