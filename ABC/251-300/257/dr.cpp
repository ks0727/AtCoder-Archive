#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int main(){
  int n;
  cin >> n;
  vector<ll> x(n),y(n),p(n);
  for(int i=0;i<n;i++) cin >> x[i] >> y[i] >> p[i];
  vector<vector<ll> > dist(n,vector<ll>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      dist[i][j] = (abs(x[i]-x[j])+abs(y[i]-y[j])+p[i]-1)/p[i];
    }
  }

  for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++){
    if(dist[i][j] > max(dist[i][k],dist[k][j])){
      dist[i][j] = max(dist[i][k],dist[k][j]);
    }
  }
  long long ans = 1e18;
  for(int i=0;i<n;i++){
    ll now = 0;
    for(int j=0;j<n;j++){
      now = max(now,dist[i][j]);
    }
    ans = min(now,ans);
  }
  cout << ans << endl;
  return 0;
}

