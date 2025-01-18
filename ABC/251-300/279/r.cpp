#include <iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
  double a,b;
  cin >> a >> b;
  long long l=0,r=1e18;
  int cnt = 1000;
  auto f = [&](long long x){
      double c = sqrt(1+x);
      double res = a/c + (double)b*x;
      return res;
  };  
  while(cnt--){
    long long high = (r*2+l)/3;
    long long low = (r+l*2)/3;
  
    if(f(high) < f(low)) l = low;
    else r = high;
  }
  double ans = f(l);
  printf("%.10f\n",ans);
}



