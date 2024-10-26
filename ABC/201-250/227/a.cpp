#include <iostream>
using namespace std;

int main(){
  int n,k,a;
  cin >> n >> k >> a;
  a--; k--;
  int ans = (a+k)%n;
  cout << ans+1 << endl;
  return 0;
}

