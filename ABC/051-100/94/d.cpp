#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  int mx = a.back();
  int ans = -1001001001;
  int l = mx/2;
  auto it = upper_bound(a.begin(),a.end(),l);
  if(it != a.end() && *it != mx){
    ans = *it;
  }
  if(it != a.begin()) it--;
  if(abs(*it - l) < abs(ans-l)) ans = *it;
  cout << mx << ' ' << ans << endl;
  return 0;
}

