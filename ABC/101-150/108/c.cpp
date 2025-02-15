#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> cnt(k);
  for(int i=1;i<=n;i++) cnt[i%k]++;
  long long ans = 0;
  for(int i=0;i<k;i++){
    if((2*k-2*i)%k == 0) ans += (long long)cnt[i]*cnt[(k-i)%k]*cnt[(k-i)%k];
  }
  cout << ans << endl;
  return 0;
}

