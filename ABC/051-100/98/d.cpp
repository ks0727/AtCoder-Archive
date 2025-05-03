#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<long long>s(n+1),x(n+1);
  for(int i=0;i<n;i++){
    s[i+1] = s[i]+a[i];
    x[i+1] = x[i]^a[i];
  }
  long long ans = 0;
  int r=0;
  for(int l=0;l<n;l++){
    while(r < n && ((s[r+1]-s[l]) == (x[r+1]^x[l]))) r++;
    ans += r-l;
  }
  cout << ans << endl;
  return 0;
}

