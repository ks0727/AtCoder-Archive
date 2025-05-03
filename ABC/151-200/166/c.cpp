#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> h(n);
  for(int i=0;i<n;i++) cin >> h[i];
  vector<vector<int> > g(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<bool> seen(n);
  int ans = 0;
  for(int i=0;i<n;i++){
    if(seen[i]) continue;
    bool ok = true;
    for(int u : g[i]){
      if(h[u] < h[i]) {
        seen[u] = true;
      }else{
        ok = false;
      }
    }
    if(ok) ans++;
  }
  cout << ans << endl;
  return 0;
}

