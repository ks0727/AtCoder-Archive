#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
const int di[] = {1,0,-1,0};
const int dj[] = {0,-1,0,1};
int main(){
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  for(int i=0;i<h;i++) cin >> s[i];
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  a--; b--; c--; d--;
  const int INF = 1e9;
  vector<vector<int> > dist(h,vector<int>(w,INF));
  dist[a][b] = 0;
  deque<pair<int,int> > q;
  q.emplace_front(a,b);
  while(!q.empty()){
    auto [i,j] = q.front(); q.pop_front();
    for(int v=0;v<4;v++){
      int ni = i + di[v]; int nj = j + dj[v];
      if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if(s[ni][nj] == '.' && dist[ni][nj] > dist[i][j]){
        dist[ni][nj] = dist[i][j];
        q.emplace_front(ni,nj);
      }
    }
    for(int v=0;v<4;v++){
      for(int st=1;st<=2;st++){
        int ni = i+di[v]*st; int nj = j+dj[v]*st;
        if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
        if(dist[ni][nj] != INF) continue;
        if(s[ni][nj] !='#') continue;
        if(dist[ni][nj] > dist[i][j] + 1){
          dist[ni][nj] = dist[i][j] + 1;
          q.emplace_back(ni,nj);
        }
      }
    }
  }
  cout << dist[c][d] << endl;
  return 0;
}

