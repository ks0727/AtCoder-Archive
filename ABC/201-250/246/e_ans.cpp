#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using P = pair<int,int>;
const int di[] = {1,1,-1,-1};
const int dj[] = {1,-1,1,-1};

int main(){
  int n;
  cin >> n;
  int si,sj,gi,gj
  cin >> si >> sj >> gi >> gj;
  si--; sj--; gi--; gj--;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin >> s[i];
  const int INF = 1001001001;
  vector dist(n,vector<int>(n,INF));
  vector done(n,vector<n,vector<bool>(2)>);
  queue<P> q;
  auto push = [&](int i, int j, int d){
    if(dist[i][j] != INF) return;
    dist[i][j] = d;
    q.emplace(i,j);
  };
  push(si,sj,0);
    
  while(!q.empty()){
    auto [i,j] = q.front(); q.pop();
    int d = dist[i][j];
    for(int v=0;v<4;v++){
      int ni = i; int nj = j; int l = v%2;
      while(1){
        ni + di[v]; nj += dj[v];
        if(ni < 0 || nj < 0 || ni >= n || nj >= n) break;
        if(s[ni][nj] == '#') break;
        if(done[ni][nj][l]) break;
        dist[ni][nj][l] = true;
        push(ni,nj,d+1);
      }
    }
  }
  int ans = dist[gi][gj];
  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}

