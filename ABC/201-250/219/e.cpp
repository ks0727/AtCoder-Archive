#include <iostream>
#include<vector>
using namespace std;
const int di[] = {1,0,-1,0};
const int dj[] = {0,-1,0,1};
int main(){
  vector<int> a(16);
  for(int i=0;i<16;i++) cin >> a[i];
  int n = 1<<16;
  int ans = 0;
  for(int i=0;i<n;i++){
    bool ok = true;
    vector<bool>need(16);
    for(int j=0;j<16;j++){
      if(i>>j&1) need[j] = true;
      if(a[j] == 1 && !(i>>j&1)){
        ok = false;
        break;
      }
    }
    if(!ok) continue;
    int sv = -1;
    for(int j=0;j<16;j++){
      if(need[j]){
        sv = j;
        break;
      }
    }
    if(sv == -1){
      ans++;
      continue;
    }
    vector<bool> visited(16);
    auto dfs1 = [&](auto dfs1, int v,int p = -1){
      visited[v] = true;
      for(int d=0;d<4;d++){
        int ni = v/4+di[d];
        int nj = v%4+dj[d];
        if(ni < 0 || nj < 0 || ni >= 4 || nj >= 4) continue;
        if(v == p) continue;
        if(visited[ni*4+nj]) continue;
        if(!need[ni*4+nj]) continue;
        dfs1(dfs1,ni*4+nj,v);
     }
    };
    dfs1(dfs1,sv);
    if(!ok) continue;
    for(int j=0;j<16;j++){
      if(need[j] && !visited[j]) break;
      if(j==15){
         ans++;
       }
    }
  }
  cout << ans << endl;
  return 0;
}

