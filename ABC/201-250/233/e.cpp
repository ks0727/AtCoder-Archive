#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long a[5<<17], s[5<<17];
int main(){
  string x;
  cin >> x;
  int n = x.size();
  for(int i=0;i<n;i++){
    a[i] = x[i]-'0';
    s[i+1] = s[i]+a[i];
  } 
  reverse(s,s+n+1);
  string ans = "";
  vector<long long> prevs(n+100);
  for(int i=0;i<n+100;i++){
    long long now = prevs[i] + s[i];
    ans += now%10 + '0';
    now /= 10;
    int cnt = 0;
    while(now>0){
      cnt++;
      prevs[i+cnt] += now%10;
      now /= 10;
    }
  }
  while(ans.back() == '0') ans.pop_back();
  reverse(ans.begin(),ans.end());
  cout << ans << endl;
  return 0;
}

