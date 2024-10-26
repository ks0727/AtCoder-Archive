#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n,d;
  cin >> n >> d;
  vector<pair<int,int> > ps(n);
  for(int i=0;i<n;i++) cin >> ps[i].first >> ps[i].second;
  for(int i=0;i<n;i++) swap(ps[i].first,ps[i].second);
  sort(ps.begin(),ps.end());
  int ans = 0;
  vector<bool> exist(n,true);
  for(int i=0;i<n;i++){
    if(!exist[i]) continue;
    int j=i+1;
    ans++;
    while(j<n && ps[j].second < ps[i].first+d){
      exist[j] = false;
      j++;
    }
  }
  cout << ans << endl;
  return 0;
}

