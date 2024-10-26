#include <iostream>
#include <map>
using namespace std;
long long a[2<<17],s[2<<17];
int main(){
  int n; long long k;
  cin >> n >> k;
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) s[i+1] = s[i]+a[i];
  map<long long,long long> mp;
  mp[0] = 1;
  long long ans = 0;
  for(int i=1;i<=n;i++){
    ans += mp[s[i]-k]; //s[i]-s[j] = k -> s[j] = s[i]-k
    mp[s[i]]++;
  }
  cout << ans << endl;
}

