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
  int ans = 0;
  for(int si=0;si<h;si++){
    for(int sj=0;sj<w;sj++){
      if(s[si][sj] == '#') continue;
      for(int gi=0;gi<h;gi++){
        for(int gj=0;gj<w;gj++){
          if(s[gi][gj] == '#') continue;
          if(si == gi && sj == gj) continue;
          queue<pair<int,int> > q;
          const int INF = 1e9;
          vector<vector<int> > dist(h,vector<int>(w,INF));
          q.emplace(si,sj);
          dist[si][sj] = 0;
          while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for(int d=0;d<4;d++){
              int ni = i+di[d]; int nj = j+dj[d];
              if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
              if(s[ni][nj] == '#' || dist[ni][nj] != INF) continue;
              dist[ni][nj] = dist[i][j] + 1;
              q.emplace(ni,nj);
            }
          }
          ans = max(ans,dist[gi][gj]);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

