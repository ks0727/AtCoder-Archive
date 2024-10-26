#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n; long long x;
  cin >> n >> x;
  vector<int> l(n);
  vector<vector<long long> > a(n);
  for(int i=0;i<n;i++){
    cin >> l[i];
    for(int j=0;j<l[i];j++){
      long long ai;
      cin >> ai;
      a[i].push_back(ai);
    }
  }
  int ans = 0;
  auto f = [&](auto f, int d, long long now)->void{
    if(d == n){
      if(now == x) ans++;
      return;
    }
    if(now > x) return;
    for(int i=0;i<l[d];i++){
      f(f,d+1,(long long)now*a[d][i]);
    }
  };
  f(f,0,(long long)1);
  cout << ans << endl;
  return 0;
}

