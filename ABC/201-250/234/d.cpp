#include <iostream>
#include <set>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  set<int> st;
  int now = -1;
  for(int i=0;i<n;i++){
    int p;
    cin >> p;
    st.insert(p);
    if(st.size() <= k-1){
      continue;
    }else{
      if(p > now){
        auto it = st.upper_bound(now);
        now = *it;
      }
      cout << now << endl;
    }
  }
  return 0;
}

