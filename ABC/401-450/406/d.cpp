#include <iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int h,w,n;
  cin >> h >> w >> n;
  vector<set<int> > cs(w),rs(h);
  for(int i=0;i<n;i++){
    int x,y;
    cin >> x >> y;
    x--; y--;
    rs[x].insert(y);
    cs[y].insert(x);
  }
  int q;
  cin >> q;
  while(q--){
    int type;
    cin >> type;
    if(type == 1){
      int x;
      cin >> x; x--;
      cout << rs[x].size() << '\n';
      for(int ri : rs[x]) cs[ri].erase(x);
      rs[x] = set<int>();
    }else{
      int y;
      cin >> y; y--;
      cout << cs[y].size() << '\n';
      for(int ci : cs[y]) rs[ci].erase(y);
      cs[y] = set<int>();
    }
  } 
  return 0;
}

