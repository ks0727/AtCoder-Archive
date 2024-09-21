#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using P = pair<int,int>;

int main(){
  int n,m;
  cin >> n>> m;
  vector<int> a(n),b(n),c(m),d(m);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cin >> b[i];
  for(int i=0;i<m;i++) cin >> c[i];
  for(int i=0;i<m;i++) cin >> d[i];
  vector<P> cs,bs;
  for(int i=0;i<n;i++){
    cs.emplace_back(a[i],-b[i]);
  }
  for(int i=0;i<m;i++) bs.emplace_back(c[i],-d[i]);
  multiset<int> st;
  for(int i=0;i<m;i++) st.insert(d[i]);
  int now = 0;
  for(int i=0;i<n;i++){
    while(now < m && cs[i].first > bs[now].first){
      if(st.count(bs[now].second)){
        st.erase(st.find(bs[now].second));
      }
      now++;
    }
    int v = -cs[i].second;
    auto it = st.lower_bound(v);
    if(it == st.end()){
      cout << "No" << endl;
      return 0;
    }
    st.erase(it);
  }
  cout << "Yes" << endl;
  return 0;

}
    

  
