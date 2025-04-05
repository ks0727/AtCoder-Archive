#include <iostream>
#include<cmath>
#include<numeric>
using namespace std;

int main(){
  long long a,b,c;
  cin >> a >> b >> c;
  long long g = gcd(a,b);
  g = gcd(g,c);
  long long ans = a/g-1;
  ans += b/g-1;
  ans += c/g-1;
  cout << ans << endl;
  return 0;
}

