#include <iostream>
using namespace std;

int main(){
  int x;
  cin >> x;
  int res = 1000 -x;
  int coins[6] = {500,100,50,10,5,1};
  int ans = 0;
  for(int i=0;i<6;++i){
    if(res >= coins[i]){
      int k = res / coins[i];
      res -= coins[i]*k;
      ans += k;
    }
  }
  cout << ans << endl;
  return 0;
}

