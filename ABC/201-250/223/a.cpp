#include <iostream>
using namespace std;

int main(){
  int x;
  cin >> x;
  if(x%100 == 0 && x/100 >= 1){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}

