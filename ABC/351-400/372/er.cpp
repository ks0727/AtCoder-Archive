#include <iostream>
#include <vector>
#include <set>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  dsu uf(n);
  vector<set<int> > groups(n);
  for(int i=0;i<n;i++) groups[i].insert(i);
  for(int qi=0;qi<q;qi++){
    int type;
    cin >> type;
    if(type == 1){
      int u,v;
      cin >> u >> v;
      u--; v--;
      int pu = uf.leader(u);
      int pv = uf.leader(v);
      if(!uf.same(u,v)){
        int l = uf.merge(u,v);
        if(l == pu){ //vがuに連結された
          for(int x : groups[pv]) groups[l].insert(x);
          groups[pv].clear();
        }else{
          for(int x : groups[pu]) groups[l].insert(x);
          groups[pu].clear();
        }
      }
    }else{
      int v,k;
      cin >> v >> k;
      v--;
      int lv = uf.leader(v);
      if(groups[lv].size() < k) cout << -1 << '\n';
      else{
        auto it = groups[lv].rbegin();
        for(int cnt=0;cnt<k-1;cnt++) it++;
        cout << *it+1 << '\n';
      }
    }
  }

  return 0;
}

