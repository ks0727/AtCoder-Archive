#include <iostream>
#include<vector>
using namespace std;

int main(){
  int h,w,k;
  cin >> h >> w >> k;
  vector<string> s(h);
  for(int i=0;i<h;i++) cin >> s[i];
  const int INF = 1001001001;
  int ans = INF;
  for(int div=0;div<(1<<h-1);div++){
    int g = 0;
    vector<int> id(h);
    for(int i=0;i<h;i++){
      id[i] = g;
      if(div>>i&1) g++;
    }
    ++g; //group数になるように調整
    vector<vector<int> > c(g,vector<int>(w));
    for(int i=0;i<g;i++) for(int j=0;j<w;j++) c[i][j] = 0;
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) c[id[i]][j] += (s[i][j]-'0');
    int num = g-1;
    if(num > k) continue;
    vector<int> now(g);
    for(int j=0;j<w;j++){
      for(int i=0;i<g;i++) now[i] += c[i][j];
      bool ok = true;
      for(int i=0;i<g;i++) if(now[i] > k) ok = false;
      if(!ok){
        num++;
        now = vector<int>(g);
        for(int i=0;i<g;i++) now[i] += c[i][j];
      }
    }
    ans = min(ans,num);
  }
  cout << ans << endl; 
  return 0;
}

