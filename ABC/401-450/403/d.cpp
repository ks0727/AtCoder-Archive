#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

int main(){
  int n,d;
  cin >> n >> d;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  map<int,int> mp;
  for(int i=0;i<n;i++) mp[a[i]]++;
  long long ans = 0;
  if (d == 0) {
    for (auto [val, cnt] : mp) ans += cnt - 1;         
    cout << ans << '\n';
    return 0;
  }
  set<int> st;
  for(int i=0;i<n;i++){
    if(st.count(a[i])) continue;
    vector<int> cnt;
    long long sum = 0;
    int cur = a[i];
    while(mp.count(cur)){
      cnt.push_back(mp[cur]);
      sum += mp[cur];
      st.insert(cur);
      cur += d;
    }
    long long zero=0,one=0;
    for(int j=0;j<cnt.size();j++){
      long long none=zero+cnt[j];
      long long nzero = max(zero,one);
      zero = nzero;
      one = none;
    }
    long long now = max(zero,one);
    ans += sum - now;
  }
  cout << ans << endl;
  return 0;
}

