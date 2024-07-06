#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

int main(){
  int h,w;
  cin >> h >> w;
  int si,sj;
  cin >> si >> sj;
  si--; sj--;
  int gi,gj;
  cin >> gi >> gj;
  gi--; gj--;
  vector<string> c(h);
  for(int i=0;i<h;++i) cin >> c[i];
  using P = pair<int,int>;
  queue<P> q;
  q.push(P(si,sj));
  const int INF = 1001001001;
  vector<vector<int> > dist(h,vector<int>(w,INF));
  dist[si][sj] = 0;
  while(!q.empty()){
    auto [i,j] = q.front(); q.pop();
    for(int d=0;d<4;++d){
      int ni = i+di[d]; int nj = j+dj[d];
      if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if(c[ni][nj] == '#') continue;
      if(dist[ni][nj] != INF) continue;
      q.push(P(ni,nj));
      dist[ni][nj] = dist[i][j]+1;
    }
  }
  cout << dist[gi][gj] << endl; 
  return 0;
}

