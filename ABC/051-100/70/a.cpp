#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a = n/100;
  int b = n%10;
  if(a == b) cout << "Yes" << endl;
  else cout << "No" << endl;  
  return 0;
}

