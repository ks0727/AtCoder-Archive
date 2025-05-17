#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> h(n),s(n);
  for(int i=0;i<n;i++) cin >> h[i] >> s[i];
  long long r=1e18,l=0;
  long long ans = 1e18;
  while(r-l>1){
    long long m = (r+l)/2;
    vector<int> idx;
    for(int i=0;i<n;i++) idx.push_back(i);
    sort(idx.begin(),idx.end(),[&](int i,int j){
      long long a = s[i]*m-s[j]*h[i];
      long long b = s[j]*m-s[i]*h[j];
      return a < b;
    }
    );
    long long now = 0;
    bool ok = true;
    for(int i=0;i<n;i++){
      long long add = h[idx[i]]+s[idx[i]]*(long long)i;
      if(add > m) ok = false;
      now += add;
    }
    if(ok){
      ans = min(ans,now);
      r = m;
    }else{
      l = m;
    }
  }
  cout << l << ' ' << r << endl;
  cout << ans << endl;
  return 0;
}

