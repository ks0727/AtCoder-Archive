#include <iostream>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(c-b == b-a) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}

