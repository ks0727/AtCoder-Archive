#include <iostream>
using namespace std;
int main(){
  int n,p;
  cin >> n >> p;
  int ans = 0;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    if(a < p) ans++;
  }
  cout << ans << endl;
  return 0;
}

