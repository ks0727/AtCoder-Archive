#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
int main(){
  int n,k;
  cin >> n >> k;
  if(k == 1){
    cout << "Infinity" << endl;
    return 0;
  }
  vector<int> x(n),y(n);
  for(int i=0;i<n;i++) cin >> x[i] >> y[i];
  map<tuple<int,int,ll>,int> cnt;
  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      int a = x[i] - x[j];
      int b = y[i] - y[j];
      if(a < 0) a -= a; b -= b;
      if(a == 0) b = 1;
      else{
        int g = gcd(a,b);
        a /= g; b /= g;
      }
      ll c = (ll)a*y[i]-b*x[i];
      cnt[tuple(a,b,c)]++;
    }
  }
  int ans = 0;
  for(auto p : cnt){
    if(p.second >= k*(k-1)/2) ans++;
  }
  cout << ans << endl;
  return 0;
}

