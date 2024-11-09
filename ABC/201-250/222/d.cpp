#include <iostream>
#include <vector>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

template<class T,auto op,auto e> struct segtree{
  int n;
  vector<T> d;
  segtree(int n){
    d.resize(2*n,e());
  }
  void update(int k){
    d[k] = op(d[2*k],d[2*k+1]);
  }
  void set(int p, T x){
    p += n;
    d[p] = x;
    while(p){
      update(p>>1);
      p>>=1;
    }
  }
  T get(int p){
    return d[p+n];
  }
  T prod(int l,int r){
    T lb = e(),rb = e();
    l += n; r+=n;
    while(r>l){
      if(l&1) lb = op(lb,d[l++]);
      if(r&1) rb = op(rb,d[--r]);
      l >>= 1;
      r >>= 1;
    }
    return op(lb,rb);
  }
  void show(){
    for(int i=0;i<n;i++) cout << d[i+n].val() << ' '; cout << endl;
  }
};

mint op(mint a,mint b){
  return a+b;
}
mint e(){
  return mint(0);
}

int main(){
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cin >> b[i];
  segtree<mint,op,e> seg(n+1);
  seg.set(0,1);
  for(int i=0;i<n;i++){
    segtree<mint,op,e> old(n+1);
    swap(old,seg);
    for(int j=a[i];j<=b[i];j++){
      seg.set(j,old.prod(0,j));
    }
    seg.show();
  }
  mint ans = 0;
  for(int i=0;i<=n;i++) ans += seg.get(i);
  cout << ans.val() << endl;
  return 0;
}

