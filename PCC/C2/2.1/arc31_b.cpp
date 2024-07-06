#include <iostream>
#include <vector>
using namespace std;

const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

int main(){
  vector<string> a(10);
  int h = 10, w = 10;
  for(int i=0;i<(10); ++i) cin >> a[i];
  for(int i=0;i<10;++i){
    for(int j=0;j<10;++j){
        vector<vector<bool> > seen(10,vector<bool>(10));
        auto dfs = [&](auto dfs, int ci,int cj)->void{
          seen[ci][cj] = true;
          for(int d = 0;d<4;++d){
              int ni = ci+di[d]; int nj = cj+dj[d];
              if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
              if(a[ni][nj] == 'x') continue;
              if(seen[ni][nj]) continue;
              dfs(dfs,ni,nj);
            }   
         };
        dfs(dfs,i,j);
        bool ok = true;
        for(int k = 0;k < 10;k++){
          if(!ok) break;
            for(int l=0;l<10;++l){
                if(a[k][l] == 'o' && !seen[k][l] ){
                    ok = false;
                    break;
                  }
              }
          }
        if(ok){
            cout << "YES" << endl;
            return 0;
           } 
      }
    } 
    cout << "NO" << endl;
  return 0;
}

