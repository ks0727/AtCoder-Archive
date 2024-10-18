#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[16][16];
int main(){
  int n;
  cin >> n;
  for(int i=0;i<2*n-1;i++){
    for(int j=0;j<2*n-i-1;j++){
      cin >> a[i][j];
    }
  }
  int ans = 0;
  auto dfs = [&](auto dfs, int v, auto arr)->void{
    if(v == n){
      int nv = n;
      int cur = 0;
      for(int i=0;i<n;i++){
        if(arr[i].size() == 1){
          cur ^= a[arr[i][0]][nv];
          nv++;
        }else if(arr[i].size() == 0){
          cur ^= a[nv][nv+1];
          nv += 2;
        }else{
          cur ^= a[arr[i][0]][arr[i][1]];
        }
      }
       ans = max(ans,cur);
       return;
    }
    for(int i=0;i<arr.size();i++){
      if(arr[i].size() < 2) dfs(dfs,v+1,arr[i].push_back(v));
    }
    dfs(dfs,v+1,arr.push_back({v}));
  };
  dfs(dfs,1,vector<vector<int> >({{0}}));
  cout << ans << endl; 
  return 0;
}

