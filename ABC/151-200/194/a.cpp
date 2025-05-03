#include <iostream>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  int x = a+b;
  if(x >= 15 && b >= 8) cout << 1 << endl;
  else if(x >= 10 && b >= 3) cout << 2 << endl;
  else if(x >= 3) cout << 3 << endl;
  else cout << 4 << endl;
  return 0;
}

