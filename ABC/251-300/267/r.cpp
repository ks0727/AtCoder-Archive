#include <iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<long long> s(n+1);
  for(int i=0;i<n;i++) s[i+1] = s[i] + a[i];
  long long ans = -1e18;
  long long temp = 0;
  for(int i=0;i<m;i++){
    temp += a[i]*(i+1);
  }
  ans = temp;
  long long now = temp;
  for(int i=m;i<n;i++){
    now -= s[i]-s[i-m];
    now += (long long)(m)*a[i];
    ans = max(ans,now);
  }
  cout << ans << endl;
}


