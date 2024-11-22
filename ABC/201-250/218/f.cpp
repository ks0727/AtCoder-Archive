#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  const int INF = 1001001001;
  vector<vector<int> > dist(n,vector<int>(n,INF));
  for(int i=0;i<m;i++){
    int s,t;
    cin >> s >> t;
    s--; t--;
    dist[s][t] = 1;
  }
  for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
  for(int i=0;i<m;i++){

  return 0;
}

