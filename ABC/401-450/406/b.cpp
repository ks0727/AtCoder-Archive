#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  long long now = 1;
  vector<long long> s(k+1);
  for(int i=0;i<k+1;i++){
    s[i] = now;
    now *= 10;
  }
  long long ans = 1;
  for(int i=0;i<n;i++){
    if(a[i] >= s[k]){
      ans = 1;
      continue;
    }
    ans *= a[i];
    if(ans >= s[k]) ans = 1;
  }
  cout << ans << endl;
  return 0;
}

