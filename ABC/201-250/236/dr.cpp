#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int x[16][16];
int main(){
  int n;
  cin >> n;
  for(int i=0;i<2*n-1;i++){
    for(int j=0;j<2*n-i-1;j++) cin >> x[i][j];
  }
  int ans = 0;
  auto f = [&](auto f,vector<pair<int,int> > ps)->void{
    if(ps.size() == n){
      int now = 0;
      for(auto [a,b] : ps){
        now ^= x[a][b-a-1];
      }
      ans = max(ans,now);
      return;
    }
    vector<bool> chosen(2*n);
    for(auto [a,b] : ps){
        chosen[a] = true;
        chosen[b] = true;
    }
    int nx = -1;
    for(int i=0;i<n*2;i++){
      if(!chosen[i]){
        nx = i;
        break;
      }
    }
    for(int i=nx+1;i<2*n;i++){
      if(!chosen[i]) {
        vector<pair<int,int> > nps = ps;
        nps.emplace_back(nx,i);
        f(f,nps);
      }
    }
  };
  f(f,vector<pair<int,int> >{});
  cout << ans << endl;
}


