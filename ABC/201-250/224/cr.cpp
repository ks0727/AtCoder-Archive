#include <iostream>
#include<vector>
#include<map>
#include<tuple>
#include<numeric>
#include<algorithm>
using namespace std;
using ll = long long;
using T = tuple<ll,ll,ll,ll>;
pair<ll,ll> rational(ll a, ll b){
  if(b < 0){
    a *= -1;
    b *= -1;
  }
  if(a==0&&b==0) return pair<ll,ll>(0,0);
  else if(a==0) return pair<ll,ll>(0,1);
  else if(b==0) return pair<ll,ll>(1,0);
  else{
    ll g = gcd(a,b);
    return pair<ll,ll>(a/g,b/g);
  }
}

int main(){
  int n;
  cin >> n;
  vector<pair<ll,ll> > ps;
  for(int i=0;i<n;i++){
    ll x,y;
    cin >> x >> y;
    ps.emplace_back(x,y);
  }
  sort(ps.begin(),ps.end());
  map<T,ll> mp;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      auto [x1,y1] = ps[i];
      auto [x2,y2] = ps[j];
      auto [anum,aden] = rational(y2-y1,x2-x1);
      auto [bnum,bden] = rational(y1*x2-x1*y2,x2-x1);
      mp[T(anum,aden,bnum,bden)]++;
    }
  }
  ll ans = (ll)n*(n-1)*(n-2)/6;
  for(auto [t,cnt] : mp){
    ans -= (ll)cnt*(cnt-1)*(cnt-2)/6;
  }
  cout << ans << endl;
  return 0;
}

