#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int> > a(n,vector<int>(n));
  for(int i=0;i<n;i++)for(int j=0;j<n;j++) cin >> a[i][j];
  int m;
  cin >> m;
  vector<vector<bool> > bad(n,vector<bool>(n));
  for(int i=0;i<m;i++){
    int x,y;
    cin >> x >> y;
    x--; y--;
    bad[x][y] = bad[y][x] = true;
  }
  vector<int> is;
  for(int i=0;i<n;i++) is.push_back(i);
  int ans = 1001001001; 
  do{
    int now = 0;
    bool ok = true;
    for(int i=0;i<n-1;i++){
      if(bad[is[i]][is[i+1]]) ok = false;
    }
    if(!ok) continue;
    for(int i=0;i<n;i++) now += a[is[i]][i];
    ans = min(ans,now);
  }while(next_permutation(is.begin(),is.end()));
  if(ans != 1001001001) cout << ans << endl;
  else cout << -1 << endl;
  return 0;
}

