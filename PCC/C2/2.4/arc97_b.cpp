#include <iostream>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;

int p[1<<17];
int main(){
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;++i) cin >> p[i],p[i]--;
  dsu uf(n);
  for(int i=0;i<m;i++){
    int x,y;
    cin >> x >> y;
    x--; y--;
    uf.merge(x,y);
  }
  int ans = n;
  for(int i=0;i<n;i++){
    if(!uf.same(i,p[i])) ans--;
  }
  cout << ans << endl;
  return 0;
}

