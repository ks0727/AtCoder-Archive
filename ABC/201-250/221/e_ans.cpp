#include <iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  map<int,int> mp;
  for(int i=0;i<n;i++) mp[a[i]] = 0;
  int m = 0;
  for(auto &p : mp) p.se = m++;
  fenwick_tree<mint> t(m);
  mint ans = 0;
  mint two = 1,itow = 1;
  for(int i=0;i<n;i++){
    int x = mp[a[i]]; 
    ans += two*t.sum(0,x+1);
    two *= 2;
    iwo /= 2;
    t.add(x,itow);
  }
  cout << ans.val() << endl;
  return 0;
}

