#include<iostream>
#include<vector>
#include<atcoder/modint>
#include<map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
int main(){
  int n,m,k;
  cin >> n >> m >> k;
  if(k < 0) k *= -1;
  vector<int> a(m);
  for(int i=0;i<m;i++) cin >> a[i],a[i]--;
  vector<vector<int> > g(n);
  vector<vector<int> > path(n,vector<int>(n,-1));
  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
    path[u][v] = i;
    path[v][u] = i;
  }
  vector<int> cnt(n-1);
  for(int i=0;i<m-1;i++){
    int sv = a[i];
    queue<int> q;
    q.push(sv);
    const int INF = 1001001001;
    vector<int> dist(n,INF),from(n);
    dist[sv] = 0;
    from[sv] = -1;
    while(!q.empty()){
      int v = q.front(); q.pop();
      for(int u : g[v]){
        if(dist[u] != INF) continue;
        q.push(u);
        dist[u] = dist[v]+1;
        from[u] = v;
      }
    }
    int u = a[i+1];
    while(from[u] != -1){
      cnt[path[u][from[u]]]++;
      u = from[u];
    }
  }
  ll sum = 0;
  for(int i=0;i<n-1;i++) sum += cnt[i];
  ll x = (sum-k)/2;
  map<ll,mint> mp;
  mp[0] = 1;
  for(int i=0;i<n-1;i++){
    map<ll,mint> old;
    swap(mp,old);
    for(auto [val,c] : old){
      mp[val]++;
      if(val+cnt[i] > x) continue;
      mp[val+cnt[i]]++;
    }
  }
  cout << mp[x].val() << endl;
}


    

      
  
  
