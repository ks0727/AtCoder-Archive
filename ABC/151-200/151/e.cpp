#include <iostream>
#include<vector>
#include<algorithm>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  mint ans = 0;
  for(int i=0;i<n;i++){
    ans -= (mint)a[i]*(mint(2).pow(n-i)-1);
    ans += (mint)a[i]*(mint(2).pow(i)-1);
  }
  cout << ans.val() << endl;
  return 0;
}

