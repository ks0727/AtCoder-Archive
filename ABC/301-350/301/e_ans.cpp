#include <iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int di[] = {1,0,-1,0};
const int dj[] = {0,-1,0,1};
void chmin(int &a,int b){
  a = min(a,b);
}
int main(){
  int h,w,T;
  cin >> h >> w >> T;
  vector<string> A(h);
  for(int i=0;i<h;i++) cin >> A[i];
  vector<P> ps;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(A[i][j] == 'o') ps.emplace_back(i,j);
    }
  }
  for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(A[i][j] == 'S') ps.emplace_back(i,j);
      }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(A[i][j] == 'G') ps.emplace_back(i,j);
    }
  }
  int n = ps.size()-2; //nはお菓子の数
  const int INF = 1001001001;
  vector<vector<int> > dist(n+2,vector<int>(n+2,INF)); //お菓子, スタート, ゴールのそれぞれの座標同士の最短距離
  for(int si=0;si<n+2;si++){
    auto [i,j] = ps[si]; 
    vector<vector<int> > d(h,vector<int>(n+2,w));
    queue<P> q;
    d[i][j] = 0;
    q.emplace(i,j);
    while(q.size()){
      auto [ci,cj] = q.front(); q.pop();
      for(int v=0;v<4;v++){
        int ni = ci+di[v]; int nj = cj+dj[v];
        if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
        if(A[ni][nj] == '#') continue;
        if(d[ni][nj] != INF) continue;
        d[ni][nj] = d[i][j]+1;
        q.emplace(ni,nj);
     }
   }
   for(int ti=0;ti<n+2;ti++){
     auto [ci,cj] = ps[ti];
     dist[si][ti] = d[ci][cj];
   }
 }
 int n2 = 1<<n;
 vector<vector<int> > dp(n2,vector<int>(n,INF));
 int sv = n,tv = n+1;
 for(int i=0;i<n;i++) {
   dp[1<<i][i] = dist[sv][i];
 }
 for(int s=0;s<n2;s++){
   for(int v=0;v<n;v++){
     if(dp[s][v] == INF) continue;
     for(int u=0;u<n;u++){
       if(!(s>>u&1)){ //まだその頂点に訪れていないならやる
          chmin(dp[s|1<<u][u],dp[s][v]+dist[v][u]);
       }
     }
    }
  }
  if(dist[sv][tv] > T){ //そもそもゴールまでT回の移動回数で到達できないなら達成不可能
    cout << -1 << endl;
    return 0;
  }
  int ans = 0;
  for(int s=0;s<n2;s++){
    for(int v=0;v<n;v++){
      if(dp[s][v]+dist[v][tv] <= T){
        ans = max(ans,__builtin_popcount(s));
      }
    }
  }
  cout << ans << endl;
  return 0;
}

