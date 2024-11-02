#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  vector<pair<int,int> > vs;
  for(int i=0;i<n;i++) vs.emplace_back(-1,-1);
  while(q--){
    int type;
    cin >> type;
    if(type == 1){
      int x,y;
      cin >> x >> y;
      x--; y--;
      vs[x].first = y;
      vs[y].second = x;
    }
    else if(type == 2){
      int x,y;
      cin >> x >> y;
      x--; y--;
      vs[x].first = -1;
      vs[y].second = -1;
    }
    else if(type == 3){
      int x;
      cin >> x;
      x--;
      int v = x;
      while(vs[v].second != -1){
        v = vs[v].second;
      }
      vector<int> ans;
      while(vs[v].first != -1){
        ans.push_back(v);
        v = vs[v].first;
      }
      ans.push_back(v);
      cout << ans.size() << ' ';
      for(int i=0;i<ans.size();i++) cout << ans[i]+1 << ' '; cout << endl;
    }
  }   
  return 0;
}

