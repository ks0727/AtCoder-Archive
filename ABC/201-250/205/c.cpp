#include <iostream>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(a == b || (abs(a) == abs(b) && c%2 == 0) ) cout << '=' << endl;
  else if(c%2 == 0){
    if(abs(a) > abs(b)) cout << ">" << endl;
    else cout << "<" << endl;
  }else{
    if(a > b) cout << ">" << endl;
    else cout << "<" << endl;
  }
  return 0;
}

