#include <iostream>
using namespace std;

int main(){
  long long n;
  cin >> n;
  long long i = 1;
  long long ans = 0;
  while(i <= n){
    long long j = n/i;
    long long ni = n/j;
    ans += n/i*(ni-i+1); 
    i = ni+1; 
  }
  cout << ans << endl;
  return 0;
}

