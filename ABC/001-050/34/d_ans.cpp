#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> w(n),p(n);
  for(int i=0;i<n;i++) cin >> w[i] >> p[i];
  double l = 0, r = 100;
  double eps = 0.0000001;
  while(r-l > eps){
    double mid = (r+l)/2;
    vector<pair<double,int> > ps;
    for(int i=0;i<n;i++){
      double extra = p[i]-mid;
      extra *= (double)w[i]/100;
      ps.emplace_back(extra,i);
    }
    //for(auto [pi,idx] : ps) cout << pi << ' '; cout << endl;
    sort(ps.rbegin(),ps.rend());
    double now = 0;
    for(int i=0;i<k;i++){
      now += ps[i].first;
    }
    if(now >= 0) l = mid;
    else r = mid;
  }
  printf("%.10f\n",l);
  return 0;
}

