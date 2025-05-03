#include <iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
  int n,m,q;
  cin >> n >> m  >> q;
  vector<set<int> > auth(n);
  vector<bool> ok(n);
  while(q--){
    int type;
    cin >> type;
    if(type == 1){
      int x,y;
      cin >> x >> y;
      x--; y--;
      auth[x].insert(y);
    }else if(type ==2){
      int x;
      cin >> x;
      x--;
      ok[x] = true;
    }else{
      int x,y;
      cin >> x >> y;
      x--; y--;
      if(ok[x]) cout << "Yes\n";
      else if(auth[x].count(y)) cout << "Yes\n";
      else cout << "No\n";
    }
  }
  return 0;
}

