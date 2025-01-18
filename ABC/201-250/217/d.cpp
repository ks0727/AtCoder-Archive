#include <iostream>
#include<set>
using namespace std;

int main(){
  int l,q;
  cin >> l >> q;
  set<pair<int,int> > st;
  st.emplace(0,l);
  while(q--){
    int c,x;
    cin >> c >> x;
    if(c == 1){
      auto it = st.upper_bound(make_pair(x,0));
      it--;
      int left = it->first;
      int right = it->second;
      st.emplace(left,x);
      st.emplace(x,right);
      it = st.erase(it);
    }
    if(c == 2){
      auto it = st.upper_bound(make_pair(x,0));
      it--;
      int left = it->first;
      int right = it->second;
      cout << right - left << endl;
    }
  }
  return 0;
}

