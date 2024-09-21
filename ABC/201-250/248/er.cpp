#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using P = pair<ll,ll>;

int main(){
  int n,k;
  cin >> n>> k;
  vector<P> ps(n);
  rep(i,n) cin >> ps[i].first >> ps[i].second;
  if(k == 1){
    cout << "Infinity" << endl;
    return 0;
  }
  const ll INF = 3e18;
  auto f = [&](ll num, ll den){
    if(den < 0){
      den *= -1;
      num *= -1;
    }else if(den == 0){
      return P(INF,0);
    }
    ll g = gcd(num,den);
    return P(num/g,den/g);
  };
  auto grad = [&](P p1, P p2){
    ll num = p2.second - p1.second;
    ll den = p2.first - p1.first;
    auto [c,d] = f(num,den);
    return P(c,d);
  };
  auto inc = [&](P p1, P p2){
    ll num = p1.first*p2.second - p2.first*p1.second;
    ll den = p1.first - p2.first;
    auto [c,d] = f(num,den);
    return P(c,d);
  }; 
  map<pair<P,P>,set<int>> mp;
  rep(i,n){
    for(int j=i+1;j<n;j++){
      auto [a,b] = grad(ps[i],ps[j]);
      auto [c,d] = inc(ps[i],ps[j]);
      //cout << a << " " << b << " " << c << " " << d << endl;
      mp[make_pair(P(a,b),P(c,d))].insert(i);
      mp[make_pair(P(a,b),P(c,d))].insert(j);
    }
  }
  ll ans = 0;
  for(auto [p,cnt] : mp){
    if(cnt.size() >= k) ans++;
  }
  cout << ans << endl;
  return 0;
}