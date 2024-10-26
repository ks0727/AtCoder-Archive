#include <iostream>
#include <vector>
#include <algorithm>
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
    int na = root(a),nb = root(b);
    if(na == nb) return;
    if(rank[na] > rank[nb]) swap(na,nb);
    rank[nb] += rank[na];
    par[na] = par[nb];
  }
  bool same(int a,int b){
    return root(a) == root(b);
  }
};

int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<int,int> > es(m);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    if(a > b) swap(a,b);
    es[i] = make_pair(a,b);
  }
  sort(es.begin(),es.end());
  int prev = 0;
  int ans = 0;
  UnionFind uf(n);
  vector<int> answers;
  for(int i=n-1;i>=0;i--){
    ans++;
    while(es.size() > 0 && es.back().first == i){
      if(!uf.same(es.back().first,es.back().second)){
        ans--;
        uf.merge(es.back().first,es.back().second);
      }
      es.pop_back();
    }
    answers.push_back(prev);
    prev = ans;
  } 
  reverse(answers.begin(),answers.end());
  for(int i=0;i<n;i++) cout << answers[i] << '\n';
  return 0;
}

