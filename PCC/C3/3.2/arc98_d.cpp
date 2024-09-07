#include <iostream>
using namespace std;
using ll = long long;

ll a[2<<17],s[2<<17],x[2<<17];
int main(){
  int n; cin >> n;
  for(int i=0;i<n;++i) cin >> a[i];
  for(int i=0;i<n;++i) s[i+1] = s[i] + a[i];
  for(int i=0;i<n;++i) x[i+1] = x[i]^a[i];
  ll ans = 0;
  int r = 0;
  for(int l=0;l<n;l++){
    while(r < n &&((x[r+1]^x[l]) == (s[r+1]-s[l]))) r++;
    //if(r==l) r++;
    ans += r - l;
  }
  cout << ans << endl; 
  return 0;
}

