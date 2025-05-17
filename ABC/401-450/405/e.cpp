#include <iostream>
#include<vector>
#include<atcoder/modint>
using namespace atcoder;
using namespace std;
using mint = modint998244353;

// combination mod prime
// https://youtu.be/8uowVvQ_-Mo?t=6002
// https://youtu.be/Tgd_zLfRZOQ?t=9928
struct modinv {
  int n; vector<mint> d;
  modinv(): n(2), d({0,1}) {}
  mint operator()(int i) {
    while (n <= i) d.push_back(-d[mint::mod()%n]*(mint::mod()/n)), ++n;
    return d[i];
  }
  mint operator[](int i) const { return d[i];}
} invs;
struct modfact {
  int n; vector<mint> d;
  modfact(): n(2), d({1,1}) {}
  mint operator()(int i) {
    while (n <= i) d.push_back(d.back()*n), ++n;
    return d[i];
  }
  mint operator[](int i) const { return d[i];}
} facts;
struct modfactinv {
  int n; vector<mint> d;
  modfactinv(): n(2), d({1,1}) {}
  mint operator()(int i) {
    while (n <= i) d.push_back(d.back()*invs(n)), ++n;
    return d[i];
  }
  mint operator[](int i) const { return d[i];}
} ifacts;
mint comb(int n, int k) {
  if (n < k || k < 0) return 0;
  return facts(n)*ifacts(k)*ifacts(n-k);
}


int main(){
  long long a,b,c,d;
  cin >> a >> b >> c >> d;
  long long n = a+b+c+d;
  mint ans = 0;
  facts(n);
  ifacts(n);
  for(long long i=0;i<=c;i++){
    mint s = comb(a+b+i,a+i);
    long long t = c-i;
    mint u = comb(t+d-1,t);
    ans += s*u;
  }
  cout << ans.val() << endl;
  return 0;
}

