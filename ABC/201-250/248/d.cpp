#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int> > is(n);
  for(int i=0;i<n;i++) cin >> a[i],a[i]--;
  for(int i=0;i<n;i++) is[a[i]].push_back(i);
  int q;
  cin >> q;
  while(q--){
    int l,r,x;
    cin >> l >> r >> x;
    r--; l--; x--;
    int ans = upper_bound(is[x].begin(),is[x].end(),r) - lower_bound(is[x].begin(),is[x].end(),l);
    cout << ans << '\n';
  }
  
  return 0;
}

