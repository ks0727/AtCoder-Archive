#include <iostream>
#include<cmath>
using namespace std;
const double PI = 3.1415926535; 

int main(){
  int a,b,h,m;
  cin >> a >> b >> h >> m;
  double atheta = (60*h+m)/720.0*2*PI;
  double btheta = (m/60.0)*2*PI;
  double ax = (double)a*sin(atheta);
  double ay = (double)a*cos(atheta);
  double bx = (double)b*sin(btheta);
  double by = (double)b*cos(btheta);
  double ans = (ax-bx)*(ax-bx)+(ay-by)*(ay-by);
  ans = sqrt(ans);
  printf("%.10f\n",ans); 
  return 0;
}

