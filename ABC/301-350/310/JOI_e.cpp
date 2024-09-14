#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int W,H;
  cin >> W >> H;
  int n;
  cin >> n;
  vector<int> x1(n),x2(n),y1(n),y2(n);
  for(int i=0;i<n;i++) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
  vector<int> x,y;
  {
    vector<int> vals;
    for(int i=0;i<n;i++){
      vals.push_back(x1[i]);
      vals.push_back(x2[i]);
      vals.push_back(x1[i]+1);
      vals.push_back(x2[i]+1);
    }
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    for(int i=0;i<n;i++){
      x1[i] = lower_bound(vals.begin(),vals.end(),x1[i]) - vals.begin();
      x2[i] = lower_bound(vals.begin(),vals.end(),x2[i]) - vals.begin();
    }
    x = vals;
  }
  {
    vector<int> vals;
    for(int i=0;i<n;i++){
      vals.push_back(y1[i]);
      vals.push_back(y2[i]);
      vals.push_back(y1[i]+1);
      vals.push_back(y2[i]+1);
    }
    
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    for(int i=0;i<n;i++){
      y1[i] = lower_bound(vals.begin(),vals.end(),y1[i]) - vals.begin();
      y2[i] = lower_bound(vals.begin(),vals.end(),y2[i]) - vals.begin();
    }
    y = vals;
  }
  int h = y.size(), w = x.size();
  vector g(w,vector<int>(h));
  for(int i=0;i<n;i++){
    g[x1[i]][y1[i]]++;
    g[x1[i]][y2[i]]--;
    g[x2[i]][y1[i]]--;
    g[x2[i]][y2[i]]++;
  }
  for(int i=0;i<w-1;i++){
    for(int j=0;j<h;j++){
      g[i+1][j] += g[i][j];
    }
  }
  for(int i=0;i<w;i++){
    for(int j=0;j<h-1;j++){
      g[i][j+1] += g[i][j];
    }
  }
  for(int i=0;i<w;i++){
    for(int j=0;j<h;j++) cout << g[i][j] << ' ';
    cout << endl;
  }
  long ans = 0;
  vector seen(w,vector<bool>(h));
  const int di[] = {1,0,-1,0};
  const int dj[] = {0,-1,0,1};
  for(int i=0;i<w;i++){
    for(int j=0;j<h;j++){
      if(g[i][j] != 0) continue;
      if(seen[i][j]) continue;
      ans++;
      queue<pair<int,int> > q;
      q.emplace(i,j);
      while(!q.empty()){
        auto [wi,hi] = q.front(); q.pop();
        for(int d=0;d<4;d++){
          int nw = wi+di[d]; int nh = hi+dj[d];
          if(nw < 0 || nh < 0 || nw >= w || nh >= h) continue;
          if(seen[nw][nh]) continue;
          if(g[nw][nh]) continue;
          seen[nw][nh] = true;
          q.emplace(nw,nh);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
 

