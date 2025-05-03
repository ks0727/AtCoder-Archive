#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;

struct UnionFind{
  int n;
  vector<int> par,rank;
  UnionFind(int n):n(n),rank(n,1),par(n){
    for(int i=0;i<n;i++) par[i] = i;
  }
  int root(int x){
    if(par[x] == x) return par[x];
    return par[x] = root(par[x]);
  }
  void merge(int a,int b){
    a = root(a); b = root(b);
    if(a == b) return;
    if(rank[a] > rank[b]) swap(a,b);
    rank[b] += rank[a];
    par[a] = par[b];
  }
  bool same(int a, int b){
    return root(a) == root(b);
  }
};
int main(){
  int n;
  cin >> n;
  set<pair<int,int> > st;
  const int di[] = {-1,-1,0,0,1,1};
  const int dj[] = {-1,0,-1,1,0,1};
  for(int i=0;i<n;i++){
    int x,y;
    cin >> x >> y;
    st.emplace(x,y);
  }
  int ans = n;
  while(!st.empty()){
    auto [x,y] = *st.begin();
    st.erase(make_pair(x,y));
    queue<pair<int,int> > q;
    q.emplace(x,y);
    int now = 1;
    while(!q.empty()){
      auto [i,j] = q.front(); q.pop();
      for(int d=0;d<6;d++){
        int ni = i+di[d];
        int nj = j+dj[d];
        if(st.count(make_pair(ni,nj))){
          st.erase(make_pair(ni,nj));
          q.emplace(ni,nj);
          now++;
        }
      }
    }
    ans -= now;
    ans++;
  }
  cout << ans << endl;
}



  
  
