#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<long long> s(n+1);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) s[i+1] = s[i] + a[i];
  long long x;
  cin >> x;
  long long ans = x/s[n]*n;
  x %= s[n];
  ans += upper_bound(s.begin(),s.end(),x) - s.begin();
  cout << ans << endl;
  return 0;
}

