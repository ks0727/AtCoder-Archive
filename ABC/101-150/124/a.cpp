#include <iostream>
#include<algorithm>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  int ans = 0;
  ans = 2*a-1;
  ans = max(ans,2*b-1);
  ans = max(ans,a+b);
  cout << ans << endl;
  return 0;
}

