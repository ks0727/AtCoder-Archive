#include <iostream>
using namespace std;

int main(){
  int x,y;
  cin >> x >> y;
  int rest = y-x;
  int ans = (rest+10-1)/10;
  if(ans<0) ans = 0;
  cout << ans << endl;
  return 0;
}

