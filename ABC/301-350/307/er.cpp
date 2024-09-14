#include <iostream>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main(){
  int n,m;
  cin >> n >> m;
  auto f = [&](int x){
    mint res = 0;
    res += m*mint(m-1).pow(n-1) - (m-1)*mint(m-2).pow(n-2);
    return res;
  };
  if(n == 2){
    mint ans = (mint)m*(m-1);
    cout << ans.val() << endl;
  }else if(n==3){
    mint ans = mint(m)*(m-1)*(m-2);
    cout << ans.val() << endl;
  }else{
    mint ans = f(n);
    cout << ans.val() << endl;
  }
  return 0;
}


