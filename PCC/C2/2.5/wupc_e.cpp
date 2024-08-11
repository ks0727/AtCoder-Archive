#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using P = tuple<ll,int,int>;
struct Edge{
  int to; ll cost;
  Edge(int to, ll cost):to(to),cost(cost){}
};

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<Edge> > g(n);
  for(int i=0;i<m;++i){
    int f,t; ll c;
    cin >> f >> t >> c;
    if(t == n-1) g[f].emplace_back(t,c);
    else if(f == n-1) g[t].emplace_back(f,c);
    else{
      g[f].emplace_back(t,c);
      g[t].emplace_back(f,c);
     }
  }
  const ll INF = 1e18;
  vector<vector<ll> >  dist4(4,vector<ll>(n,INF)), dist7(7,vector<ll>(n,INF));
  auto f = [&](vector<vector<Edge> > g, vector<vector<ll> > &dist, int k){
    dist[0][0] = 0;
    priority_queue<P,vector<P>,greater<P> > q;
    q.emplace(0,0,0);
    while(!q.empty()){
      auto [c,v,r] = q.top(); q.pop();
      if(dist[r][v] < c) continue;
      for(auto e : g[v]){
        if(dist[r][v] + e.cost < dist[(r+e.cost)%k][e.to]){
          dist[(r+e.cost)%k][e.to] = dist[r][v] + e.cost;
          q.emplace(dist[(r+e.cost)%k][e.to],e.to,(r+e.cost)%k);
        }
      }
   }
 };
 ll ans = INF;
  f(g,dist4,4);
  f(g,dist7,7);
  ans = min(dist4[0][n-1],dist7[0][n-1]);
  cout << ans << endl;
  return 0;
}

