#include <iostream>
using namespace std;
int a[1<<17];
int d[1<<17];
int main(){
  int n; cin >> n;
  for(int i=0;i<n;++i) cin >> a[i];
  for(int i=0;i<n;++i) d[i] = a[i+1] - a[i];
  int r = 0;
  long long ans = n;
  for(int l=0;l<n-1;l++){
    while(r < n-1 && d[r] > 0 ) r++;
    ans += r - l;
    if(r == l) r++;
  }
  cout << ans << endl;
  return 0;
}
