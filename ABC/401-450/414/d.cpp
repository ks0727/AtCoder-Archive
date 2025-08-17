#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<long long> x(n);
  for(int i=0;i<n;i++) cin >> x[i];
  sort(x.begin(),x.end());
  //dp[i] := 最後にiで終わっている時の最小値

  return 0;
}

