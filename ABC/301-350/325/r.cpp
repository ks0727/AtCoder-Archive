#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
using ll = long long;
int main(){
  int n;
  cin >> n;
  vector<pair<ll,ll> > ps;
  for(int i=0;i<n;i++){
    ll t,d;
    cin >> t >> d;
    ps.emplace_back(t+d,t);
  }
  sort(ps.rbegin(),ps.rend());
  long long ans = 0;
  long long prev = 0;
  while(ps.size() > 0){
    auto [a,b] = ps.back();
    
  cout << ans << endl;
}

