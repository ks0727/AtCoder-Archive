#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  const int M = 1001;
  vector<vector<int> > grid(M,vector<int>(M));
  for(int i=0;i<n;i++){
    int lx,ly,rx,ry; cin >> lx >> ly >> rx >> ry;
    grid[lx][ly]++;
    grid[lx][ry]--;
    grid[rx][ly]--;
    grid[rx][ry]++;
  }
  vector<vector<long long> > s(M+1,vector<long long>(M+1));
  for(int i=0;i<M;i++)for(int j=0;j<M;j++){
    s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + grid[i][j];
  }
  vector<long long> ans(n+1);
  for(int i=0;i<=M;i++)for(int j=0;j<=M;j++) ans[s[i][j]]++;
  for(int i=1;i<=n;i++) cout << ans[i] << '\n';
  return 0;
}

