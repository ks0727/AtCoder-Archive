#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
  int n,m; ll k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<ll> b = a;
  sort(b.begin(),b.end());
  vector<ll> s(n+1);
  for(int i=0;i<n;i++) s[i+1] = s[i]+b[i];
  ll rest = k - s[n];
  vector<ll> ans(n);
  for(int i=0;i<n;i++)
  {
    if(a[i]+rest < b[n-m]){
      ans[i] = -1;
      continue;
    }
    ll l=-1,r=rest;
    while(r-l>1)
    {
      ll mid = (r+l)/2;
      ll x = a[i]+mid;
      int id = upper_bound(b.begin(),b.end(),x)-b.begin();
      cout << id << endl;
      if(id == n){
        ll below = m;
        ll need = (x+1)*m;
        ll ls = s[id]-s[n-m];
        if(need-ls <= rest-mid) l = mid;
        else r = mid;
        continue;
      }
      if(id == 0){
        l = mid;
        continue;
      }
      id--;
      if(b[id] < b[n-m]) l = mid;
      else
      {
        ll above = n-id-1;
        ll below = m - above;
        ll d = max((ll)id-below+1,(ll)0);
        if(b[d] > a[i]){
          ll ls = s[id]-s[d-1];
          ll need = (x+1)*below;
          if(need-ls <= rest-mid) l = mid;
          else r = mid;
        }else{
          ll ls = s[id]-s[d-1]-a[i];
          if(d > 1) ls += b[d-2];
          ll need = (x+1)*below;
          if(need-ls <= rest-mid) l = mid;
          else r = mid;
        }
      }
    }
    ans[i] = r;
  }
  for(int i=0;i<n;i++) cout << ans[i] << ' '; cout << endl;
  return 0;
}

