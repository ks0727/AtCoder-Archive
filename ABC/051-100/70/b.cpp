#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int a,b,c,d;
  cin >> a >>b >> c >> d;
  int mn = max(a,c);
  int mx = min(b,d);
  cout << max(mx-mn,0) << endl;
  return 0;
}

