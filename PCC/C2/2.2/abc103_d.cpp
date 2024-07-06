#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using P = pair<int,int>;

int main(){
  int n,m;
  cin >> n >> m;
  vector<P> evs;
  for(int i=0;i<m;++i){
    int a,b;
    cin >> a >> b;
    evs.push_back(P(b,a));
  }
  sort(evs.begin(),evs.end());
  int ans = 1;
  P now = evs[0];
  for(int i=1;i<m;++i){
    if(now.first > evs[i].second) continue;
    now = evs[i];
    ans++;
  }
  cout << ans << endl;
  return 0;
}

