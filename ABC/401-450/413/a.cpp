#include <iostream>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  int ans = 0;
  for(int i=0;i<n;i++){
    int a;
    cin >> a; ans += a;
  }
  if(ans <= m) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

