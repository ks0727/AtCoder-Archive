#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[1<<17],b[1<<17],c[1<<17];

int main(){
  cin >> n;
  for(int i=0;i<n;++i) cin >> a[i];
  for(int i=0;i<n;++i) cin >> b[i];
  for(int i=0;i<n;++i) cin >> c[i];
  long long ans = 0;
  sort(a,a+n);
  sort(b,b+n);
  sort(c,c+n);
  for(int i=0;i<n;++i){
    int x = lower_bound(a,a+n,b[i]) - a;
    int y = upper_bound(c,c+n,b[i]) - c;
    ans += (long long)x*(n-y);
  }
  cout << ans << endl;
  return 0;
}

