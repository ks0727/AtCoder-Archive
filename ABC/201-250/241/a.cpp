#include <iostream>
using namespace std;
int a[10];
int main(){
  for(int i=0;i<10;i++) cin >> a[i];
  int now = 0;
  for(int i=0;i<3;i++) now = a[now];
  cout << now << endl;
  return 0;
}

