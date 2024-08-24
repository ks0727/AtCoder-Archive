#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
int a[30000],b[30000];

int main(){
  int n,k;
  cin >> n >> k;
  for(int i=0;i<n;++i) cin >> a[i];
  for(int i=0;i<n;++i) cin >> b[i];
  sort(a,a+n);
  sort(b,b+n);
  ll l=0,r = 1e18+1;
  while(r-l > 1){
    ll mid = (r+l)/2;
    int now = 0;
    ll c[n];
    for(int i=0;i<n;++i) c[i] = (ll)mid/a[i];
    for(int i=0;i<n;++i){
      int x = lower_bound(b,b+n,c[i]) - b;
      now += x;
     }
    if(now <= k) l = mid;
    else r = mid;
  }
  cout << l << endl;
  return 0;
}

