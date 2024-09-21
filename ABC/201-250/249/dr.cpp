#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  const int M = 2e5+5;
  vector<int> cnt(M+5);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cnt[a[i]]++;
  long long ans = 0;
  for(int i=1;i<=M;i++){
    for(int j=1;j*j<=i;j++){
      if(cnt[i] == 0) continue;
      if(i%j != 0) continue;
      if(cnt[j] == 0) continue;
      if(j != i/j) ans += (long long)2*cnt[i]*cnt[j]*cnt[i/j];
      else ans += (long long)cnt[i]*cnt[j]*(cnt[j]);
    }
  }
  cout << ans << endl;  
  return 0;
}

