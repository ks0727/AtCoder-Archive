#include <iostream>
#include <algorithm>
using namespace std;
long long a[2<<17];

int main(){
  long long n,k,x;
  cin >> n >> k >> x;
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a,a+n);
  reverse(a,a+n);
  long long ans = 0;
  for(int i=0;i<n;i++){
    if(k <= 0){
      ans += a[i];
      continue;
    }
    int ts = a[i] / x; //引ける分
    if(ts > k){
      ans += a[i] - k*x;
      k = 0;
      continue;
    }else k -= ts;
    ans += (long long)a[i] -(long long)ts*x;
    a[i] -= (long long)ts*x;
  }
  sort(a,a+n);
  reverse(a,a+n);
  //for(int i=0;i<n;i++) cout << a[i] << ' '; cout << endl;
  if(k > 0){
    for(int i=0;i<n;i++){
      if(k <= 0) break;
      if(a[i] >= 0 ) ans -= a[i];
      k--; 
    }
  }
  cout << ans << endl;
  return 0;
}

