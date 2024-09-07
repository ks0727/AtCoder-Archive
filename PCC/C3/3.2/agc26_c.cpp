#include <iostream>
#include <map>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<char,int> mp;
  for(int i=n;i<2*n;i++) mp[s[i]]++;
  int n2 = 1<<n;
  long ans = 0;
  for(int bit=0;bit<n2;bit++){
    string t = "", u="";
    for(int i=0;i<n;i++){
       if(bit>>i&1) t += s[i];
       else u += s[i];
    }
    map<char,int> mp2 = mp;
    bool ok = true;
    for(int i=n;i<2*n;i++){
      if(!mp2.count(s[i])){
        ok = false;
        break;
      }
      mp2[s[i]]--;
      if(mp2[s[i]] == 0) mp2.erase(s[i]);
    }
    if(ok && mp2.size() == 0) ans++;
  }
  cout << ans << endl;
  return 0;
}

