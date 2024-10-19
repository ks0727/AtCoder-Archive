#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double f(pair<int,int> a,pair<int,int> b){
  auto [x1,y1] = a;
  auto [x2,y2] = b;
  double d = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
  return sqrt(d);
}

int main(){
  int n;
  cin >> n;
  vector<pair<int,int> > ps(n);
  for(int i=0;i<n;i++) cin >> ps[i].first >> ps[i].second;
  double ans = 0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      ans = max(ans,f(ps[i],ps[j]));
    }
  }
  printf("%.10f\n",ans);
  return 0;
}

