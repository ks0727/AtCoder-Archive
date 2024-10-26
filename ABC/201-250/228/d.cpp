#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
  int q;
  cin >> q;
  int n = 1<<20;
  vector<long long> a(n);
  set<int> st;
  for(int i=0;i<n;i++){
    a[i] = -1;
    st.insert(i);
  }
  while(q--){
    int t; long long x;
    cin >> t >> x;
    if(t == 1){
      int h = x%n;
      auto it = st.lower_bound(h);
      if(it == st.end()){
        auto nit = st.lower_bound(0);
        a[*nit] = x;
        st.erase(nit);
      }else{
        a[*it] = x;
        st.erase(it);
      }
    }else if(t ==2){
      int h = x%n;
      cout << a[h] << '\n';
    }
  }
    
  return 0;
}

