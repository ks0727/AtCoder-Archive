#include <iostream>
using namespace std;

int main(){
  int x;
  cin >> x;
  if(x >= 90){
    cout << "expert" << endl;
  }else if(70 <= x){
    cout << 90 - x << endl;
  }else if(x >= 40){
    cout << 70-x << endl;
  }else{
    cout << 40- x << endl;
  }

  return 0;
}

