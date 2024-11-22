#include <iostream>
#include<set>
#include<tuple>
#include<vector>
#include<map>
using namespace std;
int main(){
  int n,q;
  cin >> n >> q;
  map<int,pair<int,int> > mp;
  vector<int> cnt(n+2,1);
  for(int i=0;i<n+2;i++) mp[i] = make_pair(i,i);

  for(;q--;){
    int type;
    cin >> type;
    if(type == 1){
      int x,c;
      cin >> x >> c;
      auto it = mp.upper_bound(x);
      it--;
      auto [l,pp] = *it;
      int nr=pp.first,nl=l;
      cnt[pp.second] -= pp.first-l+1;
      cnt[c] += pp.first-l+1;
      it = mp.erase(it);
      it--;
      {
        auto [ll,pl] = *it;
        if(pl.second == c){
          it = mp.erase(it);
          nl = ll;
          it--;
        }
      }
      it++;
      {
        auto [rl,pr] = *it;
        if(pr.second == c){
          it = mp.erase(it);
          nr = pr.first;
        }
      }
      mp[nl] = make_pair(nr,c);
    }
    else{
      int c;
      cin >> c;
      cout << cnt[c] << endl;
    }
  }   
  return 0;
}

