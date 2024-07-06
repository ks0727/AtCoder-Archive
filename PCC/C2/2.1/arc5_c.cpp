#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;
using P = pair<int,int>;
using T = pair<int,P>;
int main(){
  int h,w;
  cin >> h >> w;
  vector<string> c(h);
  for(int i=0;i<h;++i) cin >> c[i];
  vector cost(h,vector<int>(w));
  int si=0,sj=0,gi=0,gj=0;
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      if(c[i][j] == 's') si=i,sj=j;
      else if(c[i][j] == 'g') gi=i,gj=j;
      else if(c[i][j] == '#') cost[i][j] = 1;
    }
  }
  
  vector dist(h,vector<int>(w,1e9));
  dist[si][sj] = 0;
  const int di[4] = {1,0,-1,0};
  const int dj[4] = {0,1,0,-1};
  deque<P> q;
  q.push_front(P(si,sj));
  while(!q.empty()){
    auto [i,j] = q.front(); q.pop_front();
    for(int d=0;d<4;++d){
      int ni = i+di[d]; int nj = j +dj[d];
      if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if(dist[ni][nj] > dist[i][j] + cost[ni][nj]){
        dist[ni][nj] = dist[i][j] + cost[ni][nj];
        if(cost[ni][nj] == 1) q.push_back(P(ni,nj));
        else q.push_front(P(ni,nj));
      }
    }
  }
  if(dist[gi][gj] <= 2) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}

