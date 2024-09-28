#include <iostream>
#include <cmath>
using namespace std;

int main(){
  long long x;
  cin >> x;
  x = x*(x+12800000);
  double ans = sqrt(x);
  printf("%.10f",ans);
  return 0;
}

