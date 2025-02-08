#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  set<pair<int,int> > st;
  while(q--){
    int l,r;
    cin >> l >> r;
    l--; r--;
    if(st.empty()) st.emplace(l,r);
    else{
      auto it = st.upper_bound(make_pair(l,r));
      it--;
      auto [l1,r1] = *it;
      if(l <= r1){ //merge
        int nl = min(l1,l);
        int nr = max(r1,r);
        st.erase(make_pair(l1,r1));
        it++;
        if(it != st.end()){
          auto [cl,cr] = *it;
          if(nr < cl){
            st.erase(make_pair(cl,cr));
            st.emplace(nl,cr);
          }else{
            st.emplace(nl,nr);
          }
        }
      }else{ //not merge
        st.emplace(l,r);
      }
    }
  }
  if(st.size() != 1){
    cout << "No" << endl;
  }else{
    auto [l,r] = *st.begin();
    if(l == 0 && r == n-1){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}
        


  
