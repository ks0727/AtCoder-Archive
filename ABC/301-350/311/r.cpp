#include <iostream>
#include <algorithm>
using namespace std;
int g[3001][3001];

int main(){
  int h,w,n;
  cin >> h >> w >> n;
  const int INF = 1001001001;
  for(int i=0;i<=h;i++)for(int j=0;j<=w;j++) g[i][j] = -INF;
  for(int i=0;i<=h;i++) g[i][0] = 0;
  for(int j=0;j<=w;j++) g[0][j] = 0;
  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    g[a][b] = 0;
  }
  long long ans = 0;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(g[i][j] == -INF) g[i][j] = min({g[i-1][j],g[i][j-1],g[i-1][j-1]})+1;
      ans += g[i][j];
    }
  }
  cout << ans << endl;
}

