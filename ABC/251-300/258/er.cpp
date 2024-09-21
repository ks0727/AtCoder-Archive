#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
int main(){
  int n,q; ll x;
  cin >>n >> q >> x;
  vector<ll> w(n);
  for(int i=0;i<n;i++) cin >> w[i];
  vector<ll> to(n);
  ll prev = 0;
  ll v = 0;
  ll cnt = 0;
  map<ll,ll> mp;
  for(ll s=0;s<n;s++){
    while(prev < x){
      prev += w[v];
      cnt++;
      v=(v+1)%n;
    }
    to[s] = v;
    mp[s] = cnt;
    prev -= w[s];
    cnt--;
  }
  vector dub(61,vector<ll>(n));
  for(int i=0;i<n;i++) dub[0][i] = to[i];
  for(int i=0;i<60;i++){
    for(int j=0;j<n;j++) dub[i+1][j] = dub[i][dub[i][j]];
  }
  while(q--){
    ll k;
    cin >> k;
    k--;
    ll ans = 0;
    for(ll i=0;i<62;i++){
      if((k>>i)&1) {
        ans = dub[i][ans];
      }     
    }
    cout << mp[ans] << endl;
  }
}




