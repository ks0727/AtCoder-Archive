#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  map<ll,ll> mp;
  for(int i=0;i<n;i++) mp[a[i]]++;
  a.erase(unique(a.begin(),a.end()),a.end());
  ll ans = 0;
  for(int i=0;i<a.size();i++){
    if(a[i] == 1) continue;
    for(int j=0;a[j]*a[j]<=a[i];j++){
      if(a[j] == 1) continue;
      if(a[i] % a[j] == 0 && mp.count(a[i]/a[j])){
        if(a[j] == a[i]/a[j]) ans += mp[a[j]]*(mp[a[j]]-1)*mp[a[i]];
        else ans += 2*mp[a[j]]*mp[a[i]/a[j]]*mp[a[i]];
      }
    }
  }
  if(mp[1] >= 3){
    ans += mp[1]*(mp[1]-1)*(mp[1]-2);
  }
  if(mp.count(1)){
    for(auto [val,cnt] : mp){
      if(val == 1) continue;
      if(cnt >= 2){
        ans += cnt*(cnt-1)*mp[1];
      }
    }
  }
  cout << ans << endl;
  return 0;
} 
