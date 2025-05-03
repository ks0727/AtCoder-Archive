#include <iostream>
#include<vector>
#include <algorithm>
#include<map>
#include<tuple>
using namespace std;
using T = tuple<int,double,int>;
int main(){
  int n,x;
  cin >> n >> x;
  vector<long long> s(n),c(n),p(n);
  map<T,double> mp;
  for(int i=0;i<n;i++) cin >> s[i] >> c[i] >> p[i];
  auto f = [&](auto f, int rest, double cp, int bit)->double{
    if(mp.count(T(rest,cp,bit))) return mp[T(rest,cp,bit)];
    double ret = 0;
    for(int i=0;i<n;i++){
      if(bit>>i&1) continue;
      if(rest-c[i]<0) continue;
      ret = max(ret,f(f,rest-c[i],cp*(double)p[i]/100.0,bit|1<<i) + f(f,rest-c[i],cp*(double)(1-p[i]/100.0),bit) + (double)cp*s[i]*p[i]/100.0);
    }
    return mp[T(rest,cp,bit)] = ret;
  };
  double ans = f(f,x,1.0,0);
  printf("%.10f\n",ans);
  return 0;
}

