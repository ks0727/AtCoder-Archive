#include <iostream>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  int mn = 10001,mx=0;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    mn = min(a,mn);
    mx = max(a,mx);
  }
  cout << mx-mn << endl;
  return 0;
}

