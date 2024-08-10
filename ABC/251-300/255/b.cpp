#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using P = pair<ll,ll>;

ll dist(P a, P b){
  ll res = (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
  return res;
}

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(k);
  rep(i,k) cin >> a[i],a[i]--;
  vector<P> ps;
  rep(i,n){
    ll x,y;
    cin >> x >> y;
    ps.emplace_back(x,y);
  }
  ll ans = 0;
  rep(i,n){
    ll now = 8e18;
    for(int x : a){
      now = min(now,dist(ps[i],ps[x]));
    }
    ans = max(now,ans);
  }
  printf("%.10lf\n",sqrt(double(ans)));
  return 0;
}