#include <iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
  double n,a,x,y;
  cin >> n >> a >> x >> y;
  map<long long,double> mp;
  mp[0] = 0;
  auto f = [&](auto f, long long n)->double{
      if(mp.count(n)) return mp[n];
      else if(n == 0) return 0;
      double res1 = f(f,n/a)+x;
      double res2 = 0;
      for(int i=2;i<=6;i++) res2 += f(f,n/i);
      res2 += 6*y;
      res2 /= 5;
      return mp[n] = min(res1,res2);
  };
  double ans = f(f,n);
  printf("%.10f\n",ans);
}

  
