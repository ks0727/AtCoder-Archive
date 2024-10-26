#include <iostream>
using namespace std;

int main(){
  long long n;
  cin >> n;
  long long ans = 0;
  for(long long a=1;a*a*a<=n;a++){
    for(long long b=a;b*a*a<=n;b++){
      long long x = a*b;
      long long c = n/x;
      if(c >= b) ans += c-b+1;
      if(c < b) break;
    }
  }
  cout << ans << endl;
  return 0;
}

