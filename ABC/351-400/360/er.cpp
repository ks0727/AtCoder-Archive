#include <iostream>
#include <atcoder/all>
#include <vector>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
  int n,k;
  cin >> n >> k;
  if(n == 1){
    cout << 1 << endl;
    return 0;
  }

  mint x = 1;
  mint p = mint(1)/n/n;

  rep(ki,k) x = x*(1-p*2*(n-1)) + 2*p*(mint(1)-x);
  mint ans = x;
  mint q = (mint(1)-x)/(n-1);
  ans += mint(mint(n)*(mint)(n+1)/2 - 1)*q;
  cout << ans.val() << endl;
  return 0;
}

