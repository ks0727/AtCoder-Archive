#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using P = pair<int,int>;

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> a(h);
  for(int i=0;i<h;++i) cin >> a[i];
  queue<P> q;
  const int INF = 1e9;
  vector dist(h,vector<int>(w,INF));
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      if(a[i][j] == '#'){
        q.push(P(i,j));
        dist[i][j] = 0;
      }
    }
  }
  const int di[4] = {1,0,-1,0};
  const int dj[4] = {0,1,0,-1};
  while(!q.empty()){
    auto [i,j] = q.front(); q.pop();
    for(int d=0;d<4;++d){
      int ni = i+di[d]; int nj = j+dj[d];
      if(ni < 0 || nj < 0 ||ni >= h || nj >= w ) continue;
      if(dist[ni][nj] != INF) continue;
      dist[ni][nj] = dist[i][j] +1;
      q.push(P(ni,nj));
    }
  }
  int ans = 0;
  for(int i =0;i<h;++i){
    for(int j=0;j<w;++j){
      ans = max(dist[i][j],ans);
    }
  }
  cout << ans << endl;
  return 0;
}

