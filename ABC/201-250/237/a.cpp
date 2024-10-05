#include <iostream>
using namespace std;

int main(){
  long long n;
  cin >> n;
  if(n >= -(1LL<<31) && n < 1LL<<31) cout << "Yes"  << endl;
  else cout << "No" << endl;
  return 0;
}

