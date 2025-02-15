#include <iostream>
using namespace std;

int main(){
  int h,w,k;
  cin >> h >> w >> k;
  vector<string> s(h);
  for(int i=0;i<h;i++) cin >> s[i];
  vector<vector<int> > g(h,vector<int>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      g[i][j] = s[i][j]-'0';
    }
  }
  vector<vector<int> > sum(h+1,vector<int>(w+1));
  for(int i=0;i<h;i++)for(int j=0;j<w;j++) sum[i+1][j] = g[i][j] + sum[i][j];  
  for(int i=0;i<h;i++)for(int j=0;j<w;j++) sum[i][j+1] = g[i][j] + sum[i][j];
  for(int i=0;i<=h;i++){
    for(int j=0;j<=w;j++) cout << sum[i][j];
    cout << endl;
  }
  int ans = 1001001001;
  for(int i=0;i<1<<h;i++){
    vector<int> cut = {0};
    for(int ii=0;ii<h;ii++) if(i>>ii&1) cut.push_back(ii+1);
    if(cut.size() < 2) continue;
    auto f = [&](int ni,int nj,int pi,int pj){
      return sum[ni][nj] - sum[ni][pj] - sum[pi][nj] + sum[pi][pj];
    };
    int prevj = 0;
    int add = 0;
    for(int j=1;j<=w;j++){
      for(int c=1;c<cut.size();c++){
        cout << "-----------------------" << endl;
        cout << f(cut[c],j,cut[c-1],prevj) << endl;
        if(f(cut[c],j,cut[c-1],prevj) > k){
          cout << "over:" << cut[c-1] << ' ' << prevj << ' ' << cut[c] << ' ' << j << endl;
          prevj = j;  
          add++;
          break;
        }
      }
    }
    for(int x : cut) cout << x << ' '; cout << endl;
    int now = cut.size() + add;
    ans = min(ans,now);
  }
  cout << ans << endl;
  return 0;
}

