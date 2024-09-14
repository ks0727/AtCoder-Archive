#include <iostream>
#include <set>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  set<int> ng;
  const int INF = 1001001001;
  ng.insert(INF);
  for(int i=0;i<n-1;i++) if(s[i] == s[i+1]) ng.insert(i);
  while(q--){
    int type; cin >> type;
    int l,r; cin >> l >> r;
    l--; r--;
    auto del = [&](int x, bool left){
      if(x == 0) return;
      if(left) x--;
      if(ng.count(x)) ng.erase(x);
      else{
        if(left){
          ng.insert(x);
        }else{
          ng.insert(x);
        }
      }
    };

    if(type == 1){
      del(l,true);
      del(r,false);
    }
    if(type == 2){
      auto it = ng.lower_bound(l);
      if(*it >= r) cout << "Yes" << '\n';
      else cout << "No" << '\n';
    }
    //for(int x : ng) cout << x << ' '; cout << endl;
  } 
      
      
  return 0;
}

