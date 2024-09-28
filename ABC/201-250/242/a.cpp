#include <iostream>
using namespace std;

int main(){
  int a,b,c,x;
  cin >> a >> b >> c >> x;
  double ans = 1.0;
  
  if(x>a)  ans = (double)c/(b-a);
  if(x>b) ans = 0;
  printf("%.10f\n",ans);
  return 0;
}

