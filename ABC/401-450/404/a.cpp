#include <iostream>
#include<vector>
using namespace std;

int main(){
  vector<int> cnt(26);
  string s;
  cin >> s;
  for(int i=0;i<s.size();i++) cnt[s[i]-'a']++;
  for(int i=0;i<26;i++){
    if(cnt[i] == 0){
      cout << char('a'+i) << endl;
      return 0;
    }
  }
  return 0;
}

