#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(){
  int n,m,p,q,r;
  cin >> n >> m >> p >> q >> r;
  vector<vector<int> > score(n,vector<int>(m));
  for(int i=0;i<r;i++){
    int x,y,z;
    cin >> x >> y >> z;
    x--; y--;
    score[x][y] = z;
  }
  int n2 = 1<<n;
  int ans = 0;
  for(int s=0;s<n2;s++){
    int cnt = 0;
    for(int i=0;i<n;i++){
      if(s >> i & 1) cnt++;
    }
    if(cnt != p) continue;
    vector<int> ps(m);
    for(int i=0;i<n;i++){
      if(s >> i & 1){
        for(int j =0;j<m;j++){
          ps[j] += score[i][j];
        }
      }
    }
    sort(ps.rbegin(),ps.rend());
    int now = 0;
    for(int j=0;j<q;j++) now += ps[j];
    ans = max(now,ans);
  }
  cout << ans << endl;
  return 0;
}

