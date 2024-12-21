#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  long long n;
  cin >> n;
  const int M = 2e6+5;
  vector<bool> isp(M,true);
  isp[0] = isp[1] = false;
  for(int i=0;i<M;i++){
    if(!isp[i]) continue;
    for(int j=i*2;j<M;j+=i){
      isp[j] = false;
    }
  }
  vector<int> ps;
  for(int i=0;i<M;i++){
    if(isp[i]) ps.push_back(i);
  }
  long long ans = 0;
  for(int a : ps){
    long long x = 1;
    for(int j=0;j<8;j++) x *= (long long) a;
    if(x > n) break;
    ans++;
  }
  for(int x : ps){
    for(int y : ps){
      if(x <= y) break;;
      long long now = (long long)x*y;
      now = now*now;
      if(now > n) break;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

