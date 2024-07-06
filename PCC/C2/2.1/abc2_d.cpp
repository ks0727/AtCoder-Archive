#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  int x[m],y[m];
  vector<vector<bool> > good(n,vector<bool>(n));
  for(int i=0;i<(m);++i){
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
    good[x[i]][y[i]] = true;
    good[y[i]][x[i]] = true;
    }
  int n2 = 1<<n;
  int ans = 1;
  for(int i=0;i<n2;++i){
      vector<int> g;
      for(int j=0;j<n;++j){
        if(i & 1<<j){
            g.push_back(j);
          }
        }
        bool ok = true;
      for(int x : g){
          for(int y : g){
              if(x == y) continue;
              if(!good[x][y]){
                  ok = false;
                  break;
                }
            }
        }
     if(ok) ans = max(ans,int(g.size()));
    }

  cout << ans << endl;
  return 0;
}

