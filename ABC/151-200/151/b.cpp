#include <iostream>
using namespace std;

int main(){
  int n,m,k;
  cin >> n >> k >> m;
  int now = 0;
  for(int i=0;i<n-1;i++){
    int a;
    cin >> a;
    now += a;
  }
  int need = m*n;
  if(need-now > k) cout << -1 << endl;
  else{
    cout << max(0,need-now) << endl;
  }
  return 0;
}

