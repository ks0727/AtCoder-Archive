#include <iostream>
#include<map>
#include<vector>
#include<set>
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
    else if(type == 2){
      long long x; int k;
      cin >> x >> k;
      auto it = st.upper_bound(x);
      it--;
      k--;
      while(k--){
        it--;
        if(it == st.begin()) break;
      }
      if(k > 0){
        cout << -1 << endl;
      }else{
        cout << *it << endl;
      }
    }
    else if(type == 3){
      long long x; int k;
      cin >> x >> k;
      auto it = st.lower_bound(x);
      k--;
      while(k--){
        it++;
        if(it == st.end()) break;
        //cout << q << ' ' << *it << endl;
      }
      if(k > 0 || it ==  st.end()){
        cout << -1 << endl;
      }else{
        cout << *it << endl;
      }
    }
  }
}


