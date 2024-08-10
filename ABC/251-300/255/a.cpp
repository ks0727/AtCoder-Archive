#include <iostream>
using namespace std;
int a[2][2];
int main(){
  int r,c;
  cin >> r >> c;
  r--; c--;
  cin >> a[0][0] >> a[0][1];
  cin >> a[1][0] >> a[1][1];
  cout << a[r][c] << endl;
  return 0;
}

