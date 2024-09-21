#include <iostream>
using namespace std;
int a[2<<17];
int cnt[2<<17];
int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cnt[a[i]]++;
  const int M = 2e5;
  long long ans = (long long)n*(n-1)*(n-2)/6;
  for(int i=1;i<=M+5;i++){
    ans -= (long long)(n-2)*cnt[i]*(cnt[i]-1)/2;
    ans += (long long)cnt[i]*(cnt[i]-1)*(cnt[i]-2)/3;
  }
  cout << ans << endl;
  return 0;
}

