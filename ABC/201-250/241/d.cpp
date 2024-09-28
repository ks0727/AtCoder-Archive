#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
  int q;
  cin >> q;
  multiset<long long> st;
  while(q--){
    int type;
    cin >> type;
    if(type == 1){
      long long x;
      cin >> x;
      st.insert(x);
    }
    if(type == 2){
      long long x; int k;
      cin >> x >> k;
      k--;
      auto it = st.upper_bound(x);
      if(it == st.begin()){
        cout << -1 << endl;
        continue;
      }
      it--;
      bool done = false;
      for(int i=0;i<k;i++){
        if(it == st.begin()){
          done = true;
          cout << -1 << endl;
          break;
        }
        it--;
      }
      if(!done) cout << *it << endl;
    }
    if(type == 3){
      long long x; int k;
      cin >> x >> k;
      k--;
      auto it = st.lower_bound(x);
      bool done = false;
      for(int i=0;i<k;i++){
        if(it == st.end()){
          cout << -1 << endl;
          done = true;
          break;
        }
        it++;
      }
      if(!done && it == st.end()) cout << -1 << endl;
      else if(!done) cout << *it << endl;
    }
    //for(long long x : st) cout << x << ' ';
    //cout << endl;
  }
  return 0;
}

