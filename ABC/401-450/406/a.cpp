#include <iostream>
using namespace std;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  if(a < c) cout << "No" << endl;
  else if(a == c && d >= b) cout << "No" << endl;
  else cout << "Yes" << endl; 
  return 0;
}

