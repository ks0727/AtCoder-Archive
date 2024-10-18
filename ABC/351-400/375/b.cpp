#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
double dist(ll x1,ll y1,ll x2,ll y2)
{
  double res = 0;
  res = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
  res = sqrt(res);
  return res;
}

int main(){
  int n;
  cin >> n;
  vector<P> ps(n);
  for(int i=0;i<n;i++) {
    cin >> ps[i].first >> ps[i].second;
  }
  double ans = 0;
  long long cx= 0,cy = 0;
  for(int i=0;i<n;i++) 
  {
    ll nx = ps[i].first;
    ll ny = ps[i].second;
    ans += dist(cx,cy,nx,ny);
    cx = nx; 
    cy = ny;
  }
  ans += dist(cx,cy,0,0);
  printf("%.10f\n",ans);
  return 0;
}

