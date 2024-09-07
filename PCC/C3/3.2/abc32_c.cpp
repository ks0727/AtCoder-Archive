#include <iostream>
using namespace std;
long a[1<<17];


int main(){
  int n,k;
  cin >> n >> k;
  for(int i=0;i<n;++i) cin >> a[i];
  for(int i=0;i<n;++i) if(a[i] == 0){
    cout << n << endl;
    return 0;
  }
  int r = 0;
  long sum = 1;
  int ans = 0;
  for(int l=0;l<n;++l){
    while(r < n && sum*a[r] <= k){
      sum *= a[r];
      r++;
    }
    ans = max(ans,r-l);
    if(r == l ) r++;
    else sum /= a[l];
  }
  cout << ans << endl;
  return 0;
}
