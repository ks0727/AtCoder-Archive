#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using P = pair<int,int>;
const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

int main(){
  int h,w,n;
  cin >> h >> w >> n;
  vector<string> c(h);
  for(int i=0;i<h;++i) cin >> c[i];
  int ssi = -1,ssj=-1;
  vector<P> pos(n+1); 
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      if(c[i][j] == '.' || c[i][j] == 'X') continue;
      if(c[i][j] == 'S'){
        pos[0] = P(i,j);
      }else{
        pos[c[i][j]-'0'] = P(i,j);
      }
    }
  }
  long ans = 0;
  for(int ni=0;ni<n;++ni){
    auto [si,sj] = pos[ni];
    queue<P> q;
    q.push(P(si,sj));
    const int INF = 1e9;
    vector<vector<int> > dist(h,vector<int>(w,INF));
    dist[si][sj] = 0;
    while(!q.empty()){
      auto [i,j] = q.front(); q.pop();
      for(int d=0;d<4;++d){
        int ni = i+di[d]; int nj = j + dj[d];
        if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
        if(c[ni][nj] == 'X') continue;
        if(dist[ni][nj] != INF) continue;
        q.push(P(ni,nj));
        dist[ni][nj] = dist[i][j]+1;
      }
    }
    auto [gi,gj] = pos[ni+1];
    ans += dist[gi][gj];
  }
  cout << ans << endl;
  return 0;
}

