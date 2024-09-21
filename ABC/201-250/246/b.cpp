#include <iostream>
#include <cmath>
using namespace std;

int main(){
  double a,b;
  cin >> a >> b;
  double d = a*a+b*b;
  d = sqrt(d);
  printf("%.10f %.10f\n",a/d,b/d);
  return 0;
}

