#include <iostream>
#include <set>
#include <queue>
using namespace std;
using P = pair<int,int>;
using ll = long long;

int n,m;
int t[2<<17],w[2<<17],s[2<<17];
ll ans[2<<17];
bool out[2<<17];
int main(){
 cin >> n >> m;
 for(int i=0;i<m;++i) cin >> t[i] >> w[i] >> s[i];
  priority_queue<P,vector<P>,greater<P>>  q;
  set<int> st;
  for(int i=0;i<n;++i) st.insert(i);
  for(int i=0;i<m;++i){
    while(!q.empty() && q.top().first <= t[i]){
      auto [l,person] = q.top(); q.pop();
      st.insert(person);
    }
    if(st.empty()) continue;
    auto eat = st.begin();
    ans[*eat] += w[i];
    q.emplace(t[i]+s[i],*eat);
    st.erase(eat);
  }
  for(int i=0;i<n;i++) cout << ans[i] << endl;
  return 0;
}

