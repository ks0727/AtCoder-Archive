#include <iostream>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  int ans = 0;
  if(h == 1 || w == 1){
    cout << h * w << endl;
    return 0;
  }
  for(int i=0;i<h;i++)for(int j=0;j<w;j++) {
    if(i%2 == 0 && j % 2 == 0)ans ++;
  }
  cout << ans << endl;
  return 0;
}

