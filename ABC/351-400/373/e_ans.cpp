#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
  int n,m; ll k;
  cin >> n >> m >> k;
  vector<ll> A(n);
  for(int i=0;i<n;i++) cin >> A[i];
  if(n == m){
    for(int i=0;i<n;i++) cout << 0 << ' '; cout << endl;
    return 0;
  }
  vector<ll> a = A;
  sort(a.begin(),a.end());
  map<int,ll> ans;
  vector<ll> s(n+1);
  for(int i=0;i<n;i++) s[i+1] = s[i] + a[i];
  ll remain = k - s[n];
  for(int i=0;i<n;i++){
    auto f = [&](ll x){
      ll y = a[i]+x;
      int r = upper_bound(a.begin(),a.end(),y+1)-a.begin(); //y+1の境界を求める
      int l = n-m;
      if(r < l) return false;
      ll need = (y+1)*(r-l) - (s[r]-s[l]);
      if(l <= i && i < r){
        need += a[i];
        need -= a[l-1];
      }
      return need > remain-x;
    };
    ll r = remain+1, l=-1;
    while(r-l>1){
      ll mid = (l+r)/2;
      if(f(mid)) l = mid;
      else r = mid;
    }
    if(l == remain+1) l = -1;
    ans[a[i]] = l;
  }
  for(int i=0;i<n;i++) cout << ans[A[i]] << ' '; cout << endl;
  return 0;
}

