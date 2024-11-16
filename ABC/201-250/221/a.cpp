#include <iostream>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  int res = 1;
  for(int i=0;i<a-b;i++) res *= 32;
  cout << res << endl;
  return 0;
}

