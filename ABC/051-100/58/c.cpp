#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin >> s[i];
  vector<int>cnt(26,1001001001);
  for(int i=0;i<n;i++){
    vector<int> cnt2(26);
    for(int j=0;j<s[i].size();j++) cnt2[s[i][j]-'a']++;
    for(int j=0;j<26;j++) cnt[j] = min(cnt[j],cnt2[j]);
  }
  for(int i=0;i<26;i++){
    if(cnt[i] == 1001001001) continue;
    for(int j=0;j<cnt[i];j++) cout << char(i+'a');
  }
  cout << endl;
  return 0;
}

