#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int main(){
  long long n;
  cin >> n;
  const ll M = 1e6;
  vector<ll> xs;

  auto f = [&](ll x,ll y){
    ll res = (x+y)*(x*x+y*y);
    return res;
  };
  for(ll a = 0;a <= M; a++){
      ll lb = -1, rb = 1e6;
      while(rb - lb > 1){
        ll mid = (rb+lb)/2;
        if(f(a,mid) >= n) rb = mid;
        else lb = mid;
      }
      xs.push_back(f(a,rb));
  }
  sort(xs.begin(),xs.end());
  xs.erase(unique(xs.begin(),xs.end()),xs.end());
  ll ans = *lower_bound(xs.begin(),xs.end(),n);
  cout << ans << endl;
  return 0;
}

