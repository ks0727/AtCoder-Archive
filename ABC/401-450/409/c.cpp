#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
  long long n,l;
  cin >> n >> l;
  vector<long long> d(n-1);
  for(int i=0;i<n-1;i++) cin >> d[i];
  if(l%3 != 0){
    cout << 0 << endl;
    return 0;
  }
  vector<long long> s(n);
  for(int i=0;i<n-1;i++) s[i+1] = (s[i]+d[i])%l;
  map<long long,long long> mp;
  for(int i=0;i<n;i++){
    mp[s[i]]++;
  }
  long long ans = 0;
  for(auto [val,cnt] : mp){
    if(val-l/3 < 0 || val + l/3 > l) continue;
    if(mp.count(val-l/3) && mp.count(val+l/3)){
      ans += cnt*mp[val-l/3]*mp[val+l/3];
    }
  }
  cout << ans << endl;
  return 0;
}

