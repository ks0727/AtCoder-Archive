#include <iostream>
#include<algorithm>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;

struct P{
  int s,d;
  P(int s=0,d=0):s(s),d(d){}
};

P e(){
  return (0,0);
}
P op(P a, P b){
  P res;
  res.s = a.s+b.s;
  res.d = min(a.d,a.s+b.d);
  return res;
}

int main(){
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  segtree<P,op,e> seg(n);
  auto f = [&](char c){
    if(c == '(') return P(1,0);
    else return P(-1,-1);
  };
  for(int i=;i<n;i++) seg.set(i,f(s[i]));
  while(q--){
    int type,l,r;
    cin >> type >> l >> r;
    l--;
    if(type == 1){
      r--;
      swap(s[l],s[r]);
      seg.set(l,f(s[l]));
      seg.set(r,f(s[r]));
    }else{
      P p = seg.prod(l,r);
      if(p.s == 0 && p.d == 0){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }
  }
  return 0;
}

