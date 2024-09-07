#include <iostream>
using namespace std;
int a[1<<17];
bool seen[1<<17];
int main(){
  int n; cin >> n;
  for(int i=0;i<n;++i) cin >> a[i],a[i]--;
  int r = 0;
  int ans = 0;
  for(int l=0;l<n;++l){
    while(r < n && !seen[a[r]]){
      seen[a[r]] = true;
      r++;
    }
    ans = max(r-l,ans);
    if(l == r ) r++;
    else seen[a[l]] = false;
  }
  cout << ans << endl;
  return 0;
}

