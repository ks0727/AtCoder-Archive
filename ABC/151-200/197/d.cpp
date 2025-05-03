#include <iostream>
#include<cmath>
using namespace std;
const double PI = 3.1415926535;
int main(){
  double n;
  cin >> n;
  double x0,y0;
  cin >> x0 >> y0;
  double x2,y2;
  cin >> x2 >> y2;
  double cx = (x0+x2)/2;
  double cy = (y0+y2)/2;
  double theta = 2*PI/n;
  double dx = x0-cx, dy = y0-cy;
  double ax = dx*cos(theta)-dy*sin(theta);
  double ay = dx*sin(theta)+dy*cos(theta);
  printf("%.10f %.10f\n",ax+cx,ay+cy);
  return 0;
}

