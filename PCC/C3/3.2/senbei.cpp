#include <iostream>
#include <vector>
using namespace std;

int main(){
  int r,c;
  cin >> r >> c;
  vector<vector<int> > g(r,vector<int>(c));
  for(int i=0;i<r;i++)for(int j=0;j<c;j++) cin >> g[i][j];
  int r2 = 1<<r;
  int ans = 0;
  for(int s=0;s<r2;s++){
    int now = 0;
    for(int i=0;i<c;i++){
      int col = 0;
      for(int j=0;j<r;j++){
         if(g[j][i] == 1 && (s>>j)&1)col++;
         else if(g[j][i] == 0 && ~(s>>j)&1) col++;
      }
      now += max(col,r-col);
    }
    ans = max(ans,now);
  }
  cout << ans << endl;   
  return 0;
}

