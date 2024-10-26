#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int l,r;
  cin >> l >> r;
  l--; r--;
  string s;
  cin >> s;
  string t = s.substr(l,r-l+1);
  reverse(t.begin(),t.end());
  string ans = "";
  for(int i=0;i<l;i++) ans += s[i];
  ans += t;
  for(int i=r+1;i<s.size();i++) ans+=s[i];
  cout << ans << endl;
  return 0;
}

