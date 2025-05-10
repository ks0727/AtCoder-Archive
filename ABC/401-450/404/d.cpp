#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<long long> c(n);
  for(int i=0;i<n;i++) cin >> c[i];
  vector<int> k(m);
  vector<vector<int> > a(m);
  vector<vector<int> > b(n);
  for(int i=0;i<m;i++){
    cin >> k[i];
    for(int j=0;j<k[i];j++){
      int ai;
      cin >> ai;
      ai--;
      a[i].push_back(ai);
      b[ai].push_back(i);
    }
  }
  long long ans = 1e18;
  auto dfs = [&](auto dfs, int d, vector<int> cnt,long long now)->void{
    if(d == n){
      for(int i=0;i<m;i++){
        if(cnt[i] < 2) return;
      }
      ans = min(ans,now);
      return;
    }
    for(int i=0;i<3;i++){
      vector<int> cnt2=cnt;
      for(int j=0;j<b[d].size();j++){
        cnt2[b[d][j]] += i;
      }
      long long now2 = now + (long long)i*c[d];
      dfs(dfs,d+1,cnt2,now2);
    }
  };
  dfs(dfs,0,vector<int>(m),0LL);
  cout << ans << endl;
  return 0;
}

