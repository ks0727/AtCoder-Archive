#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  long long l=0,r=2e10;
  while(r-l>1){
    int mid = (r+l)/2;
    auto f = [&](long long x){
      long long res = 0;
      for(int i=0;i<n;i++) res = max(0,a[i]-x);
      return res;
    };
    if(f(mid) < k) r = mid;
    else l = mid;
  }
  long long ans = 0;
  auto asum = [&](long long l, long long r){
    return (l+r)*(r-l+1)/2;
  };
  for(int i=0;i<n;i++){
    if(a[i] <= l) continue;
    ans += asum(ac+1,a[i]);
  }
  ans += l*(k-f(l));
  cout << ans << endl;
  return 0;
}

