#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans = 0;
  if(n%2){
    ans = n/2*(n/2+1);
  }else{
    ans = n/2*n/2;
  }
  cout << ans << endl;
  return 0;
}

