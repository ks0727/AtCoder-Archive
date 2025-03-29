#include <iostream>
using namespace std;

int main(){
  long long n;
  cin >> n;
  long long a,b,c;
  cin >> a >> b >> c;
  const int M = 10000;
  long long ans = 1001001001;
  for(long long i=0;i<M;i++){
    if(i*a > n) continue;
    for(long long j=0;j<M;j++){
      if(i*a + j*b > n) continue;
      long long rest = n - i*a- j*b;
      if(rest%c != 0) continue;
      long long k = rest / c;
      ans = min(ans, i+j+k);
    }
  }
  cout << ans << endl;
  return 0;
}

