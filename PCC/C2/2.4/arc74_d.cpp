#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<int> a(3*n);
  rep(i,3*n) cin >> a[i];
  priority_queue<int> r;
  priority_queue<int,vector<int>,greater<int> > l;
  ll rsum = 0,lsum = 0;
  rep(i,n){
    lsum += a[i];
    l.push(a[i]);
  }
  for(int i=3*n-1;i>=2*n;i--){
    rsum += a[i];
    r.push(a[i]);
  }
  ll orgl = lsum, orgr= rsum;
  ll ans = -1e18;
  vector<ll> lsums(n),rsums(n);
  rep(i,n){
    lsum += a[i+n];
    l.push(a[i+n]);
    lsum -= l.top(); l.pop();
    lsums[i] = lsum;
    //cout << lsum << endl;
  }
  rep(i,n){
    rsum += a[2*n-1-i];
    r.push(a[2*n-1-i]);
    rsum -= r.top(); r.pop();
    rsums[i] = rsum;
    //cout << rsum << endl;
  }
  reverse(rsums.begin(),rsums.end());
  rep(i,n+1){
    if(i-1 < 0) ans = max(ans,orgl-rsums[i]);
    else if(i == n) ans = max(ans,lsums[i-1]-orgr);
    else ans = max(ans,lsums[i-1]-rsums[i]);
  } 
  cout << ans << endl;
  return 0;
}