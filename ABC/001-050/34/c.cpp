#include <iostream>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
mint modfact(int x){
  if(x == 1) return mint(1);
  mint res = x;
  return res*modfact(x-1);
}
int main(){
  int w,h;
  cin >> w >> h;
  w--; h--;
  mint num = modfact(w+h);
  mint den1 = modfact(w);
  mint ans = num/den1;
  mint den2 = modfact(h);
  ans /= den2;
  cout << ans.val() << endl; 
  return 0;
}

