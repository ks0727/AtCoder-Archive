#include <iostream>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int ans = a*100+10*b + c;
  if(ans%4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}

