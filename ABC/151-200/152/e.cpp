#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<vector<pair<int,int>> > p(n);
  vector<int> cnt(n+1);
  vector<bool> isp(n+1,true);
  isp[0] = isp[1] = false;
  for(int i=2;i<=n;i++){
    if(!isp[i]) continue;
    for(int j=i;j<=n;j+=i) isp[j] = false;
  }
  for(int i=0;i<n;i++){
    int now = a[i];
    for(int j=2;j*j<=n;j++){
      if(now%j!= 0) continue;
      int e = 0;
      while(now%j==0) {
        e++;
        now /= j;
      }
      p[i].emplace_back(j,e);
      cnt[j] = max(cnt[j],e);
    }
    if(now != 1) p[i].emplace_back(now,1);
  }
  vector<vector<pair<int,int>> > xs;
  for(int i=0;i<n+1;i++) if(cnt[i] != 0) xs.emplace_back(i,cnt[i]);
  long long ans = 0;
  for(int i=0;i<n;i++){
    long long now = 0;
    for(auto [pi,e] : p[i]){
      
  return 0;
}

