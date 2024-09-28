#include <iostream>
#include <algorithm>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n==1){
      cout << s[0]-'A'+1 << endl;
      continue;
    }else if(n==2){
      int ans = s[0]-'A';
      if(s[0]>=s[1]) ans++;
      cout << ans << endl;
    }
    mint ans = 0;
    mint one = 1;
    int m = (n+1)/2;
    int k = (n-1)/2;
    string x = "";
    for(int i=0;i<k;i++) one *= 26;
    for(int i=0;i<m;i++){
      char now = 'A';
      while(now < s[i]){
        now++;
        ans += one;
      }
      x+=s[i];
      one /= 26;
    }
    string ns = s.substr(0,n/2);
    reverse(ns.begin(),ns.end());
    x += ns;
    if(x<=s) ans++;
    cout << ans.val() << endl;
  }
  return 0;
}

