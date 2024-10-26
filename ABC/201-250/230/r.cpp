#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<int,int> > ps(m);
  for(int i=0;i<m;i++) cin >> ps[i].first >> ps[i].second;
  for(int i=0;i<m;i++) swap(ps[i].first,ps[i].second);
  sort(ps.begin(),ps.end());
  int ans = 0;
  int t = 0;
  for(int i=0;i<m;i++){
    if(ps[i].second >= t){
      ans++;
      t = ps[i].first;
    }
  }
  cout << ans << endl; 
  return 0;
}

