#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  int n,w;
  cin >> n >> w;
  vector<pair<long long,int> > ps(n);
  for(int i=0;i<n;i++) cin >> ps[i].first >> ps[i].second;
  sort(ps.rbegin(),ps.rend());
  long long ans = 0;
  for(int i=0;i<n;i++){
    int use = min(w,ps[i].second);
    ans += (long long)ps[i].first*use;
    w -= use;
    if(w <= 0) break;
  }
  cout << ans << endl; 
  return 0;
}

