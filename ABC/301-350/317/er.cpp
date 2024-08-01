#include <iostream>
#include <queue>
#include <cassert>
using namespace std;
using P = pair<int,int>;
const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

string a[2000];
bool cango[2000][2000];
int visited[2000][2000];
int main(){
  int h,w;
  cin >> h >> w;
  int si = -1,sj = -1;
  int gi = -1, gj = -1;
  for(int i=0;i<h;++i)for(int j=0;j<w;j++) cin >> a[i],cango[i][j]=true;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j] == '.') continue;
      else if(a[i][j] == 'S') si=i,sj=j;
      else if(a[i][j] == 'G') gi=i,gj=j;
      else if(a[i][j] == '#') cango[i][j] = false;
      else{
        int ni = i,nj = j;
        int d = -1;
        if(a[i][j] == '>') d=1;
        else if(a[i][j] == '<') d = 3;
        else if(a[i][j] == 'v') d = 0;
        else d = 2;
        ni += di[d]; nj += dj[d];
        cango[i][j] = false;
        if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        while(0 <= ni && ni < h && 0 <= nj && nj < w && (a[ni][nj] == '.'||a[ni][nj] == 'S' ||a[ni][nj]=='G')){
          assert(0 <= ni && ni < h && 0 <= nj && nj < w);
          cango[ni][nj] = false;
          ni += di[d]; nj += dj[d];
        }
      }
    }
  }
  assert(si != -1 && sj != -1 && gi != -1 && gj != -1);
  queue<P> q;
  q.emplace(si,sj);
  for(int i=0;i<h;++i)for(int j=0;j<w;++j) visited[i][j] = -1;
  visited[si][sj] = 0;
  while(!q.empty()){
    auto [i,j] = q.front(); q.pop();
    for(int d=0;d<4;d++){
      int ni = i + di[d]; int nj = j + dj[d];
      if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
      if(visited[ni][nj] != -1 || !cango[ni][nj]) continue;
      visited[ni][nj] = visited[i][j] + 1;
      q.emplace(ni,nj);
    }
  }
  cout << visited[gi][gj] << endl;
  return 0;
}

