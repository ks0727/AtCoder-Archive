#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
  vector<pair<ll,ll> > ps;
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    long long x,y;
    cin >> x >> y;
    ps.emplace_back(x,y);
  }
  auto f = [&](pair<ll,ll> a, pair<ll,ll> b){
    if(a.second*(b.first-1)>b.second*(a.first-1)) return false;
    else if(a.second*(b.first-1)==b.second*(a.first-1)){
       return a.second*b.first <= a.first*b.second;
    }else return true;
  };
  sort(ps.begin(),ps.end(),f);
  int ans = 0;
  ll px=0,py=-1;
  for(int i=0;i<n;i++){
    auto [xi,yi] = ps[i];
    if(py*xi > (yi-1)*(px-1)) continue;
    if(py*xi == yi*px) continue;
      px=xi;
      py=yi;
      ans++;
    if(px == 0) break;
  }
  cout << ans << endl;
  return 0;
}


