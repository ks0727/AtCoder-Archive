#include <iostream>
#include<vector>
#include<numeric>
using namespace std;

int main(){
  long long n,m;
  cin >> n >> m;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  long long lc = 1;
  for(int i=0;i<n;i++) lc = lcm(a[i],lc);
  long long cnt = 1;
  long long ans = 0;
  while(true){
    if(lc*cnt/2 <= m) ans++;
    else{
      break;
    }
    cnt += 2;
  }
  cout << ans << endl;
  return 0;
}

