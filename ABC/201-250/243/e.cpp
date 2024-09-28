#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
ll dist[300][300];
int main(){
  int n,m;
  cin >> n >> m;
  const ll INF = 1e18;
  for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i!=j) dist[i][j] = INF;
  vector ei(n,vector<int>(n,-1));
  for(int i=0;i<m;i++){
    int a,b; ll c;
    cin >> a >> b >> c;
    a--; b--;
    dist[a][b] = dist[b][a] = c;
    ei[a][b] = ei[b][a] = i;
  }
  set<int> noneed; 
  for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++){
    if(dist[i][j] > dist[i][k]+dist[k][j]){
      if(dist[i][j] != INF && ei[i][j] != -1) noneed.insert(ei[i][j]);
      dist[i][j] = dist[i][k] + dist[k][j];
    }
  }
  cout << noneed.size() << endl;
  return 0;
}

