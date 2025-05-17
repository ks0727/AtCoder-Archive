#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int di[] = {1,0,-1,0};
const int dj[] = {0,-1,0,1};
int main(){
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  for(int i=0;i<h;i++) cin >> s[i];
  queue<pair<int,int> > q;
  vector<string> ans = s;
  for(int i=0;i<h;i++)for(int j=0;j<w;j++) if(s[i][j] == 'E') q.emplace(i,j);
  while(!q.empty()){
    auto [i,j] = q.front(); q.pop();
    //for(int i=0;i<h;i++) cout << ans[i] << endl;
    //cout << "-------------------" << endl;
    for(int d=0;d<4;d++){
      int ni = i+di[d];
      int nj = j+dj[d];
      if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if(ans[ni][nj] != '.') continue;
      q.emplace(ni,nj);
      if(d == 0) ans[ni][nj] = '^';
      else if(d == 1) ans[ni][nj] = '>';
      else if(d == 2) ans[ni][nj] = 'v';
      else if(d == 3) ans[ni][nj] = '<';
    }
  }
  for(int i=0;i<h;i++) cout << ans[i] << endl;
  return 0;
}

