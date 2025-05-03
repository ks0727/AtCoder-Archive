#include <iostream>
#include<vector>
using namespace std;

int main(){
  int h,w,x,y;
  cin >> h >> w >> x >> y;
  x--; y--;
  vector<string>s(h);
  for(int i=0;i<h;i++) cin >> s[i];
  if(s[x][y] == '#'){
    cout << 0 << endl;
    return 0;
  }
  const int di[] = {1,0,-1,0};
  const int dj[] = {0,-1,0,1};
  int ans = 1;
  for(int d=0;d<4;d++){
    int cx = x; int cy = y;
    while(cx>=0&&cy>=0&&cx<h&&cy<w){
      cx += di[d]; cy += dj[d];
      if(cx < 0 || cy < 0 || cx >= h || cy >= w) break;
      if(s[cx][cy] == '#') break;
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}

