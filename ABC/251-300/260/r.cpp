#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

struct UnionFind{
  int n;
  vector<int> par,rank;
  UnionFind(int n):n(n),par(n),rank(n,1){
    for(int i=0;i<n;i++) par[i] = i;
  }
  int root(int x){
    if(par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  void merge(int a,int b){
    int na = root(a);
    int nb = root(b);
    if(na == nb) return;
    if(rank[na] > rank[nb]) swap(na,nb);
    rank[nb] += rank[na];
    par[na] = nb;
  }
  bool same(int a, int b){
    return root(a) == root(b);
  }
  int size(int a){
    return rank[root(a)];
  }
};


int main(){
  int n,k;
  cin >> n >> k;
  vector<int> p(n);
  for(int i=0;i<n;i++) cin >> p[i],p[i]--;
  set<int> st;
  vector<int> last(n,-1);
  vector<int> sz(n,1);
  vector<int> ans(n,-1);
  for(int i=0;i<n;i++){
    auto it = st.lower_bound(p[i]);
    if(it == st.end()){
      sz[p[i]] = 1;
      if(sz[p[i]] == k){
        ans[p[i]] = i+1;
      }else{
        st.insert(p[i]);
      }
    }else{
      int x = *it;
      last[p[i]] = x;
      sz[p[i]] = sz[x] + 1;
      if(sz[p[i]] == k){
        st.erase(it);
        int v = p[i];
        while(v != -1){
          ans[v] = i+1;
          v = last[v];
        }
      }else{
        st.erase(it);
        st.insert(p[i]);
      }    
    }
  }
  for(int i=0;i<n;i++){
    cout << ans[i] << endl;
  }
}


