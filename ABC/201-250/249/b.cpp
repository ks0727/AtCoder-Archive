#include <iostream>
#include <map>
using namespace std;

int main(){
  string s;
  cin >> s;
  map<char,int> mp;
  bool l=false,u=false;
  for(int i=0;i<s.size();i++){
    if('a' <=s[i] && s[i] <= 'z') l = true;
    else if('A' <= s[i] && s[i] <= 'Z') u = true;
    if(mp.count(s[i])){
      cout << "No" << endl;
      return 0;
    }
    mp[s[i]]++;
  }
  if(l && u) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

