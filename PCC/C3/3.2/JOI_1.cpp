#include <iostream>
#include <vector>
using namespace std;
using P = pair<int,int>;
int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<P> ps;
  int j = 0;
  for(int i=0;i<n;i++){
    while(j < n-1 && a[j] != a[j+1]) j++;
    ps.push_back(P(i,j));
    i = j;
    if(i == n-1) break;
    j++;
  }
  int sz = ps.size();
  if(sz == 1 || sz == 2){
    cout << n << endl;
    return 0;
  }
  int ans = 0;
  for(int i=0;i<sz-2;i++){
    auto [l,r] = ps[i];
    auto [nl,nr] = ps[i+2];
    ans = max(ans,nr-l+1);
  }
  cout << ans << endl;
  return 0;
}

