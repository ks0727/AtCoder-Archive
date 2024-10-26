#include <iostream>
#include <vector>
using namespace std;

int main(){
  string t;
  cin >> t;
  int k;
  cin >> k;
  int n = t.size();
  vector<int> a(n),s(n+1);
  for(int i=0;i<n;i++) a[i] = t[i] == '.'?1:0;
  for(int i=0;i<n;i++) s[i+1] = a[i]+s[i];
  //for(int i=0;i<n+1;i++) cout << s[i] << ' '; cout << endl;
  int r = 0;
  int ans = 0;
  for(int l=1;l<n+1;l++){
    while(r <= n && s[r]-s[l-1]<=k) r++;
    ans = max(ans,r-l);
    if(l==r) r++;
  }
  cout << ans << endl;
  return 0;
}

