#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
  int n; ll x;
  cin >> n >> x;
  vector<ll> w(n);
  for(int i=0;i<n;i++) cin >> w[i];
  vector<ll> a,b;
  int sz=0,sz2 = 0;
  if(n%2 == 0) sz = n/2,sz2 = n/2;
  else sz = n/2+1, sz2 = n/2;
  for(int i=0;i<1<<sz;i++){
    ll now = 0;
    for(int j=0;j<sz;j++){
      if(i>>j&1) now += w[j];
    }
    a.push_back(now);
  }
  for(int i=0;i<1<<sz2;i++){
    ll now = 0;
    for(int j=0;j<sz2;j++){
      if(i>>j&1) now += w[j+sz];
    }
    b.push_back(now);
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  ll ans = 0;
  for(int i=0;i<b.size();i++){
    ans += upper_bound(a.begin(),a.end(),x - b[i]) - lower_bound(a.begin(),a.end(),x- b[i]);
  }
  cout << ans << endl;
  return 0;
}

