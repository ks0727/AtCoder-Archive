#include <iostream>
#include <map>
#include <vector>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
int t[1<<10];
int main(){
  int n,x;
  cin >> n >> x;
  for(int i=0;i<n;i++) cin >> t[i];
  mint p = (mint)1/n;
  map<int,mint> memo;
  auto f = [&](auto f,int v)->mint{
    if(memo.count(v)) return memo[v];
    if(v > x) return (mint)p;
    mint res = 0;
    for(int i=0;i<n;i++)
    {
      if(i == 0) res += (mint)p;
      else res += f(f,v+t[i]);
    }
    return memo[v] = res;
  };
  mint ans = f(f,0);
  cout << ans.val() << endl;
  return 0;
}

