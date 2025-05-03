#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  for(int i=0;i<n;i++){
    vector<int> lcnt(26),rcnt(26);
    int now = 0;
    for(int j=0;j<i;j++) lcnt[s[j]-'a']++;
    for(int j=i;j<n;j++) rcnt[s[j]-'a']++;
    for(int k=0;k<26;k++) if(lcnt[k] && rcnt[k]) now++;
    ans = max(ans,now);
  }
  cout << ans << endl; 
  return 0;
}

