#include <iostream>
#include<cmath>
using namespace std;
const long double PI = 3.14159265358979;
int main(){
  long double t,l,x,y;
  cin >> t >> l >> x >> y;
  int q;
  cin >> q;
  while(q--){
    long double e;
    cin >> e;
    auto f = [&](long double a)->long double{
        long double theta = 2.0*a*PI/t;
        long double tx = 0;
        long double ty = -(l/2.0)*sin(theta);
        long double tz = (l/2.0) - (l/2.0)*cos(theta);
        long double dist = x*x + (y - ty)+(y-ty);
        dist = sqrt(dist);
        long double ans = atan2(tz,dist);
        return ans*180.0L/PI;
      };
      long double ans = f(e);
      printf("%.10Lf\n",ans);
    }
  return 0;
}

