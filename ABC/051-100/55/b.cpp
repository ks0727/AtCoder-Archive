#include <iostream>
using namespace std;
const int MOD = 1000000007;
int main(){
  long long n;
  cin >> n;
  long long ans = 1;
  for(long long i=n;i>=1;i--){
    ans *= (long long)i;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}

