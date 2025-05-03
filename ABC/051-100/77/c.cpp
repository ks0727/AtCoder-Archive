#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n),b(n),c(n);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cin >> b[i];
  for(int i=0;i<n;i++) cin >> c[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
  vector<long long> s(n+5);
  vector<long long> ok(n);
  for(int i=n-1;i>=0;i--){
    ok[i] = c.end() - upper_bound(c.begin(),c.end(),b[i]);
  }
  for(int i=n;i>=0;i--){
    s[i-1] = s[i] + ok[i-1];
  }
  long long ans = 0;
  for(int i=0;i<n;i++){
    int id = upper_bound(b.begin(),b.end(),a[i]) - b.begin();
    ans += s[id];
  }
  cout << ans << endl;
  return 0;
}

