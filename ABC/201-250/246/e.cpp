#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  int ax,ay,bx,by;
  cin >> ax >> ay >> bx >> by;
  ax--; ay--; bx--; by--;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin >> s[i];
  const int INF = 1e9;
  vector<vector<int> > cost(n,vector<int>(n,INF));
  vector<vector<int> > visit(n,vector<int>(n,INF));
  
  deque<P> q;
  visit[ax][ay] = 0;
  cost[ax][ay] = 0;
  q.emplace(ax,ay);
  const int di[] = {1,1,-1,-1};
  const int dj[] = {1,-1,1,-1};
  while(!q.empty()){
    auto [i,j] = q.front(); q.pop();
    for(int d=0;d<4;d++){
      int ni = i+di[d]; int nj = j+dj[d];
      if(ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
      
    }
  }
  if(visit[bx][by] == INF) cout << -1 << endl;
  else cout << visit[bx][by] << endl;

  return 0;
}

