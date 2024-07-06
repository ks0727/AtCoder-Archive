#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
  ll x,y;
  cin >> x >> y;
  int ans = 0;
  for(ll n = x;n<=y;n*=2){  
    ans++;
  }
  cout << ans << endl;
  return 0;
}

