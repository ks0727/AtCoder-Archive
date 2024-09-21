#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using P = pair<int,int>;
int main(){
  int n,m;
  cin >> n>> m;
  vector<P> p(n),q(m);
  for(int i=0;i<n;i++) cin >> p[i].first;
  for(int i=0;i<n;i++) cin >> p[i].second;
  for(int i=0;i<m;i++) cin >> q[i].first;
  for(int i=0;i<m;i++) cin >> q[i].second;
  sort(p.rbegin(),p.rend());
  sort(q.rbegin(),q.rend());
  int qi = 0;
  multiset<int> s;
  for(int i=0;i<n;i++){
    auto [x,y] = p[i];
    while(qi < n && q[qi].first >= x){
      s.insert(q[qi].second);
      qi++;
    }
    auto it = s.lower_bound(y);
    if(it == s.end()){
      cout << "No" << endl;
      return 0;
    }
    s.erase(it);
  }
  cout << "Yes" << endl;
  return 0;
}

