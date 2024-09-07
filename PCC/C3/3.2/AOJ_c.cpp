#include <iostream>
using namespace std;
int a[1<<17];
int main(){
  int n,q; cin >> n >> q;
  for(int i=0;i<n;++i) cin >> a[i];
  while(q--){
    long long x;
    cin >> x;
    int r = 0;
    long long ans = 0;
    long long sum = 0;
    for(int l=0;l<n;++l){
      while(r<n && sum + a[r] <= x){
        sum += a[r];
        r++;
      }
      ans += r-l;
      if(r == l) r++;
      else sum -= a[l];
    }
    cout << ans << '\n';
  }

  return 0;
}
