#include <iostream>
#include<queue>
#include <vector>
using namespace std;
const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};
using P = pair<int,int>;
int main(){
  int h,w;
  cin >> h >> w;
  vector<string> c(h);
  for(int i=0;i<h;++i) cin >> c[i];
  int si = -1,sj = -1;
  int gi=-1,gj = -1;
  for(int i=0;i<h;++i)for(int j=0;j<w;j++){
        if(c[i][j] == 's'){
            si = i; sj = j;
         }else if(c[i][j] == 'g'){
            gi = i; gj = j;
           }
    }

 queue<P> q;
 q.push(P(si,sj));
 vector<vector<bool> > seen(h,vector<bool>(w));
 while(!q.empty()){
    auto [i,j] = q.front(); q.pop();
    if(i == gi && j == gj){
      cout << "Yes" << endl;
      return 0;
    }
    for(int d=0;d<4;++d){
        int ni = i+di[d]; int nj = j + dj[d];
        if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
        if(c[ni][nj] == '#') continue;
        if(seen[ni][nj]) continue;
        
        seen[ni][nj] = true;
        q.push(P(ni,nj));
      }
   }
   cout << "No" << endl;
  return 0; 
}

