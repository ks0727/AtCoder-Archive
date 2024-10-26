#include <iostream>
#include <vector>
#include <atcoder/modint>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
using mint = modint998244353;
int main(){
  int n,m;
  cin >> n >> m;
  dsu uf(n);
  vector<P> es;
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a  >> b;
    a--; b--;
    es.emplace_back(a,b);
    uf.merge(a,b);
  }
  vector<int> numV(n),cumE(n); //頂点と辺の数を数える
  for(auto [a,b] : es){
    numE[uf.leader(a)]++;
  }
  mint ans = 1;
  for(int i=0;i<n;i++) numV[uf.leader(i)]++;
  for(int i=0;i<n;i++){
    if(numV[i] == 0) continue;
    if(numV[i] != numE[i]) ans = 0;
    ans*=2;
  }
  cout << ans.val() << endl;
  return 0;
}

