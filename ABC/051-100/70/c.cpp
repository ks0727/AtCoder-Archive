#include <iostream>
#include <numeric>
using namespace std;

int main(){
  int n;
  cin >> n;
  long long ans = 1;
  for(int i=0;i<n;i++){
    long long l;
    cin >> l;
    ans = lcm(l,ans);
  }
  cout << ans << endl;
  return 0;
}

