#include <iostream>
#include <map>
#include <vector>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

mint sum(mint x)
{
  return x*(x+1)/2;
}

int main(){
  long long n;
  cin >> n;
  int digit = 0;
  long long t = n;
  vector<mint> vs;
  long long cur = 9;;
  long long now = 1;
  for(int i=0;i<19;i++)
  {
    vs.push_back(cur*now);
    now *= 10;
  }
  while(t)
  {
    t /= 10;
    digit++;
  }
  long long s = 1;
  digit--;
  for(int i=0;i<digit;i++) s*= 10;
  long long ord = n - s + 1;;
  mint ans = sum(ord);
  digit--;
  while(digit>=0)
  {
    ans += sum(vs[digit]);
    digit--;
  }
  cout << ans.val() << endl;
}
    
