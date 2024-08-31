#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i],a[i]--;

  vector<bool> finished(n);
  vector<int> win(n);
  
  rep(i,n){
    if(finished[i]) continue;
    int v = i;
    set<int> visited;
    bool skip = false;
    while(!visited.count(v)){
      visited.insert(v);
      v = a[v];
      if(finished[v]){
        skip = true;
        break;
      }
    }
    for(int x : visited) finished[x] = true;  
    if(skip) continue;
    int u = v;
    do{
      win[u] = true;
      u = a[u];
    }while(u != v);
  }
  
  int ans = 0;
  rep(i,n) if(win[i]) ans++;
  cout << ans << endl;
  return 0;
}