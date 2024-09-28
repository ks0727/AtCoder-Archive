#include <iostream>
using namespace std;

int main(){
  int v,a,b,c;
  cin >> v >> a >> b >> c;
  int sum = a+b+c;
  v %= sum;
  if(v < a) cout << 'F' << endl;
  else if(v < a+b) cout << 'M' << endl;
  else cout << 'T' << endl;
  return 0;
}

