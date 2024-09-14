#include <iostream>
#include <map>
using namespace std;
string s[15];
int main(){
  int n,k;
  cin >> n >> k;
  int n2 = 1<<n;
  for(int i=0;i<n;i++) cin >> s[i];
  int ans = 0;
  for(int i=0;i<n2;i++){
    map<char,int> mp;
    for(int j=0;j<n;j++){
      if(i>>j&1){
        for(int l=0;l<s[j].size();l++) mp[s[j][l]]++;
      }
    }
    int now = 0;
    for(auto [c,num] : mp) if(num == k) now++;
    ans = max(now,ans);
  }
  cout << ans << endl;
  return 0;
}

