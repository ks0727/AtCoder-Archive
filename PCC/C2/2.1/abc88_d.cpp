#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  for(int i=0;i<h;++i) cin >> s[i];
  const int INF = 1e9;
  vector dist(h,vector<int>(w,INF));
  dist[0][0] = 0;
  using P = pair<int,int>;
  queue<P> q;
  q.push(P(0,0));
  const int di[4] = {1,0,-1,0};
  const int dj[4] = {0,1,0,-1};

  while(!q.empty()){
    auto [i,j] = q.front(); q.pop();
    for(int d=0;d<4;++d){
      int ni = i +di[d]; int nj = j + dj[d];
      if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if(dist[ni][nj] != INF) continue;
      if(s[ni][nj] == '#') continue;
      q.push(P(ni,nj));
      dist[ni][nj] = dist[i][j]+1;
    }
  }
  if(dist[h-1][w-1] == INF){
    cout << -1 << endl;
    return 0;
  }
  int ans = h*w;
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      if(s[i][j] == '#') ans--;
    }
  }
  ans -= dist[h-1][w-1]+1;
  cout << ans << endl;
  return 0;
}

