#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  int ans = 0;
  for(int i=0;i<s.size()-2;i++){
    if(s.substr(i,3) == "ABC") ans++;
  }
  while(q--){
    int x; char c;
    cin >> x >> c;
    x--;
    int l = max(0,x-2);
    int r = min((int)s.size(),x+2);
    int now = 0;
    for(int i=l;i<r;i++){
      if(s.substr(i,3) == "ABC") now++;
    }
    s[x] = c;
    int nxt = 0;
    for(int i=l;i<r;i++){
      if(s.substr(i,3) == "ABC") nxt++;
    }
    int diff = nxt - now;
    ans += diff;
    cout << ans << '\n';
  }
}
