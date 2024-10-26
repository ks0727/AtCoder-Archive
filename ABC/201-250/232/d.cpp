#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> c(h); 
  for(int i=0;i<h;i++) cin >> c[i];
  const int INF = 1e9;
  vector<vector<int> > dist(h,vector<int>(w,-INF));
  const int di[] = {0,1};
  const int dj[] = {1,0};
  
  dist[0][0] = 1;
  queue<pair<int,int> > q;
  q.emplace(0,0);
  while(!q.empty()){
    auto [i,j] = q.front(); q.pop();
    for(int d=0;d<2;d++){
      int ni = i+di[d];
      int nj = j+dj[d];
      if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if(c[ni][nj] == '#') continue;
      if(dist[ni][nj] != -INF) continue;
      dist[ni][nj] = dist[i][j]+1;
      q.emplace(ni,nj);
    }
  }
  int ans = 0;
  for(int i=0;i<h;i++)for(int j=0;j<w;j++) ans = max(ans,dist[i][j]);
  cout << ans << endl;
}
