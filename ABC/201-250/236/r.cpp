#include <iostream>
#include<vector>
#include <set>
#include<map>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector a(2*n-1,vector<int>(2*n-1));
  for(int i=0;i<2*n-1;i++){
    for(int j=0;j<2*n-1-i;j++){
      cin >> a[i][j];
    }
  }
  int ans = 0;
  auto dfs = [&](auto dfs,set<int> rest, int now=0){
    if(rest.size() == 0){
      ans = max(ans,now);
      return;
    }
    set<int> st = rest;
    int f = *st.begin();
    st.erase(f);
    for(int x : st){
      set<int> nxt = st;
      nxt.erase(x);
      dfs(dfs,nxt,now^a[f][x-f-1]);
    }
  };
  set<int> rest;
  for(int i=0;i<2*n;i++){
    rest.insert(i);
  }
  dfs(dfs,rest,0);
  cout << ans << endl;
}



  
