#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <numeric>
#include <tuple>
using namespace std;
using T = tuple<long long,long long,long long,long long>;
int main(){
  int n;
  cin >> n;
  vector<pair<long long,long long> > ps(n);
  for(long long i=0;i<n;i++) cin >> ps[i].first >> ps[i].second;
  sort(ps.begin(),ps.end());
  map<pair<int,int>,int > mp;
  auto rational = [&](long long nume, long long deno)->pair<long long,long long>{
    if(deno == 0) return make_pair(1,0);
    else if(nume == 0) return make_pair(0,1);
    long long g = gcd(nume,deno);
    return make_pair(nume/g,deno/g);
  };
  auto coef = [&](pair<long long,long long> p1, pair<long long,long long> p2)->pair<long long,long long>{
    auto [x1,y1] = p1;
    auto [x2,y2] = p2;
    auto [deno,nume] = rational(y2-y1,x2-x1);
    return make_pair(deno,nume);
  };
  auto inte = [&](pair<long long,long long> p1, pair<long long,long long> p2,bool isinf = false)->pair<long long,long long>{
    if(isinf) return make_pair(0,1);
    auto [x1,y1] = p1;
    auto [x2,y2] = p2;
    auto [deno,nume] = rational(x2*y1-x1*y2,x2-x1);
    return make_pair(deno,nume);
  };
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      auto [a,b] = coef(ps[i],ps[j]);
      mp[make_pair(a,b)]++;
    }
  }
  long long ans = mp.size()*2;                         
  cout << ans << endl;
  return 0;
}

