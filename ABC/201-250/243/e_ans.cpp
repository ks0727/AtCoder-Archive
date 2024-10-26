#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
  int n,m;
  cin >> n,m;
  const ll INF = 1e18;
  vector<vector<ll> > g(n,vector<int>(n,INF));
  vector dist(n,vector<ll>(n,INF));
  for(int i=0;i<n;i++) dist[i][i] = 0;
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    --a; --b;
    g[a][b] = c;
    dp[a][b] = dp[b][a] = c;
  }
  for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
  int ans = 0;
  for(int i=0;i<n;i++)for(int j=0;j<n;j++){
    if(g[i][j] == INF) continue; //そこに辺がないならcontinue
    bool ok = false;
    for(int k=0;k<n;k++){
      if(dp[i][k]+dp[k][j] <= g[i][j]) ok = true;
    }
    if(ok) ans++;
  }
  cout << ans << endl;
  return 0;
}

