#include <iostream>
#include <map>
using namespace std;
string s[100];
int main(){
  int n;
  cin >> n;
  map<string,int> mp;
  for(int i=0;i<n;i++){
    cin >> s[i];
    mp[s[i]]++;
  }
  string ans = "";
  int mx = 0;
  for(auto [t,cnt] : mp){
    if(cnt > mx){
      ans = t;
      mx = cnt;
    }
  }
  cout << ans << endl;
  return 0;
}

