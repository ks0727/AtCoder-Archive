#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int now = 0;
  while(n > now*1000) now++;
  cout << now*1000 - n << endl;
  return 0;
}

