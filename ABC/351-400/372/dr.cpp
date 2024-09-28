#include <iostream>
#include <vector>
#include <set>
using namespace std;
int h[2<<17];
int ans[2<<17];
int to[2<<17];
int nxt [2<<17];
int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++) cin >> h[i],h[i]--;
  for(int i=0;i<n;i++){
    ans[i] = -1;
     to[i] = -1;
     nxt[i] = i<n-1?h[i+1]:-1;
  }
  set<int> st;
  for(int i=0;i<n;i++){
    if(st.size() == 0){
      st.insert(h[i]);
      continue;
    }
    auto it = st.lower_bound(h[i]);
    vector<int> visit;
    if(it == st.end()){
      for(int x : st){
        to[x] = h[i];
        visit.push_back(x);
      }
    }else{
      for(int x : st){
        if(x == *it) break;
        to[x] = h[i];
        visit.push_back(x);
      }
    }
    for(int x : visit) st.erase(x);
    st.insert(h[i]);
  }
  for(int i=0;i<n;i++){
    auto f = [&](auto f, int v)->int{
       if(ans[v] != -1) return ans[v];
       if(to[v] == -1) return ans[v] = 1;
       return ans[v] = f(f,to[v])+1;
     };
    f(f,i);
  }
  for(int i=0;i<n;i++){
    if(nxt[i] == -1) cout << 0 << ' ';
    else{
      cout << ans[nxt[i]]  << ' ';
    }
  }
  cout << endl;
}


