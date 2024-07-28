#include <iostream>
#include <set>
#include <stack>
using namespace std;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  set<P> st;
  for(int i=0;i<n;++i){
    int l,r;
    cin >> l >> r;
    st.insert(P(l,r));
  }
  stack<P> sta;
  int pl = 0,pr = 0;
  for(auto [l,r] : st){
    if(l > pr){
      sta.push(P(pl,pr));
      pl = l; pr = r;
    }else if(l >= pl && r >= pr){
      pr = r;
    }else if(l >= pl && r < pr){
      continue;
    }
  }
  if(sta.top().first != pl || sta.top().second != pr) sta.push(P(pl,pr));
  set<P> ans;
  while(!sta.empty()){
    ans.insert(sta.top()); sta.pop();
  }
  ans.erase(P(0,0));
  for(auto [l,r]:ans){
    cout << l << ' ' << r << endl;
  }
  return 0;
}

