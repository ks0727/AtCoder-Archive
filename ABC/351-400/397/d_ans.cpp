#include <iostream>
using namespace std;

int main(){
  long long n;
  cin >> n;
  for(long long d=1;d*d*d<n;d++){
    long long c = n - d*d*d;
    if(c%(3*d) != 0) continue;
    c /= 3*d;
    long long y = (-d + sqrt(d*d+4*c))/2;
    if(y*y+d*y-c == 0){
      cout << y+d << ' ' << y << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}

