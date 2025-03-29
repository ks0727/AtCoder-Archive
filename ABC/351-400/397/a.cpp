#include <iostream>
using namespace std;

int main(){
  string x;
  cin >> x;
  int a = int(x[0]-'0')*10+(x[1]-'0');
  int b = (x[3]-'0');
  if(a >= 38){
    cout << 1 << endl;
  }else if(a ==37 && b >= 5){
    cout << 2 << endl;
  }else{
    cout << 3 << endl;
  }
  return 0;
}

