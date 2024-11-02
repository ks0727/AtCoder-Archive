#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using P = pair<int,int>;
template<class T,auto op,auto e> struct segtree{
  int n;
  vector<T> d;
  segtree(int n):n(n){
    d.resize(n*2,e());
  }
  void set(int p,T x){
    p += n;
    d[p] = x;
    while(p){
      update(p>>1);
      p >>= 1;
    }
  }
  T get(int p){
    return d[p+n];
  }
  T prod(int l,int r){
    T rb = e(),lb = e();
    l += n; r += n;
    while(l < r){
      if(l&1) lb = op(lb,d[l++]);
      if(r&1) rb = op(rb,d[--r]);
      l >>= 1;
      r >>= 1;
    }
    return op(rb,lb);
  }
  void update(int k){
    d[k] = op(d[2*k],d[2*k+1]);
  }
};

int e(){
  return 1001001001;
}
int op(int a,int b){
  return min(a,b);
}

vector<int> compress(vector<int> arr){
  vector<int> cp = arr;
  sort(cp.begin(),cp.end());
  cp.erase(unique(cp.begin(),cp.end()),cp.end());
  return cp;
}

int main(){
  int n;
  cin >> n;
  map<int,vector<P> > ps;
  vector<int> bs;
  for(int i=0;i<n;i++){
    vector<int> a(3);
    for(int j=0;j<3;j++) cin >> a[j];
    sort(a.begin(),a.end());
    ps[a[0]] .emplace_back(a[1],a[2]);
    bs.push_back(a[1]);
  }
  bs = compress(bs); //ソートして重複をなくしたもの
  segtree<int,op,e> seg(bs.size());
  for(auto [a,bc] : ps){
     for(auto [b,c] : bc){
       int bi = upper_bound(bs.begin(),bs.end(),b) - bs.begin()-1;
       if(seg.prod(0,bi) < c){ //もしそれより小さいBの中で出てきたCの中で, 今のでたものよりも小さいものがあれば条件を満たす
         cout << "Yes" << endl;
         return 0;
       }
     }
     for(auto [b,c] : bc){
       int bi = upper_bound(bs.begin(),bs.end(),b) - bs.begin()-1;
       seg.set(bi,op(c,seg.get(bi))); //そのbiの値にはそこにセットされていた値と, それまでの最小の値のうち小さい値をsetしておく
    }
  }
  cout << "No" << endl;
  return 0;
}

