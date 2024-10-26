#include <iostream>
#include <queue>
#include <vector>
using namespace std;

long long modpow(int x, int k, int mod){
  long long res = 0;
  if(k == 0) return 1;
  res = ((modpow(x,k/2,mod)%mod)*modpow(x,k/2,mod)%mod)%mod;
  if(k % 2 == 1) {
    res *= x;
    res %= mod;
  }
  return res%mod;
}
int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int> > g(n);
  vector<int> dim(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
    dim[a]++;
    dim[b]++;
  }
  queue<int> q;
  for(int i=0;i<n;i++) if(dim[i] == 1) q.push(i);
  while(!q.empty()){
    int v = q.front(); q.pop();
    for(int u : g[v]){
      dim[u]--;
      if(dim[u] == 1) q.push(u);
    }
  }
  int cycle = 0;
  for(int i=0;i<n;i++){
   if(dim[i] > 1){
     auto dfs = [&](auto dfs, int v)->void{
       dim[v]--;
       for(int u:g[v]){
         if(dim[u] > 1) dfs(dfs,u);
       }
     };
     dfs(dfs,i);
     cycle++;
   }
 } 
  if(cycle == 0){
    cout << 0 << endl;
    return 0;
  }

  long long ans = modpow(2,cycle,998244353);
  cout << ans << endl;
  return 0;
}

