#include <iostream>
using namespace std;

int main(){
  int n,x;
  cin >> n>> x;
  int y =(x-1)/n;
  char ans = 'A'+y;
  cout << ans << endl;
  return 0;
}

