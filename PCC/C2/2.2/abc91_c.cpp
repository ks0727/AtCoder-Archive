#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using P = pair<int,int>;
int main(){
  int n;
  cin >> n;
  vector<P> as(n),bs(n);
  for(int i=0;i<n;++i){
    int a,b;
    cin >> a >> b;
    as[i]  = P(a,b);
  }
  for(int i=0;i<n;++i){
    int a,b;
    cin >> a >> b;
    bs[i]  = P(a,b);
  }
  sort(as.begin(),as.end());
  sort(bs.begin(),bs.end());
  int ans = 0;
  vector<bool> used(n);
  for(int i=n-1;i>=0;i--){
    auto [ax,ay] = as[i];
    int cj = n-1;
    int good = -1;
    int mn = 1001001001;
    while(cj >= 0 && bs[cj].first >ax){
      if(bs[cj].second < mn && bs[cj].second >ay && !used[cj]){ 
        good = cj;
        mn = bs[cj].second;
      }
      cj--;
    }
    if(good == -1) continue;
    used[good] = true;
    ans++;
  }
  cout << ans << endl;
  return 0;
}

