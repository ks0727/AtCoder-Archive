#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

int main(){
  int n; string t;
  cin >> n >> t;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin >> s[i];
  vector<int> front,back;
  auto f = [&](string ns){
    int fr = 0, ba = 0;
    int now = 0;
    for(int i=0;i<ns.size();i++){
      if(now >= t.size()) break;
      if(ns[i] == t[now]){
        fr++;
        now++;
      }
    }
    now = t.size()-1;
    for(int i=ns.size()-1;i>=0;i--){
      if(now < 0) break;
      if(ns[i] == t[now]){
        ba++;
        now--;
      }
    }
    front.push_back(fr);
    back.push_back(ba);
  };
  for(int i=0;i<n;i++) f(s[i]);
  sort(front.begin(),front.end());
  sort(back.begin(),back.end());

  assert(front.size() == n);
  assert(back.size() == n);
  //for(int i=0;i<n;i++) cout << front[i] << ' '; cout << endl;
  //for(int i=0;i<n;i++) cout << back[i] << ' '; cout << endl;
  long long ans = 0;
  int r = n-1;
  for(int l=0;l<n;l++){
    while(r >= 0 && front[l]+back[r]>=t.size()) r--;
    ans += n-r-1;
  }
  cout << ans << endl;
  return 0;
}

