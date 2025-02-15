#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

double dist(pair<double,double> p1,pair<double,double> p2){
  auto [x1,y1] = p1;
  auto [x2,y2] = p2;
  double res = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
  return res;
}

int main(){
  int n;
  cin >> n;
  vector<pair<double,double> > ps;
  for(int i=0;i<n;i++){
    double x,y;
    cin >> x >> y;
    ps.emplace_back(x,y);
  }
  double sum = 0;
  vector<int> is;
  for(int i=0;i<n;i++) is.push_back(i);
  double all = 0;
  do{
    sum++;
    double now = 0;
    for(int i=0;i<n-1;i++){
      now += dist(ps[is[i]],ps[is[i+1]]);
    }
    all += sqrt(now);
  }while(next_permutation(is.begin(),is.end()));
  double ans = sqrt(all)/sum;
  printf("%.10f\n",ans);
  return 0;
}

