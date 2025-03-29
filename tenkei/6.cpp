#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> cnt(26);
  for(int i=0;i<n-k+1;i++) cnt[s[i]-'a']++;
  string ans = "";
  int idx = 0;
  for(int i=0;i<k;i++){
    int target = 0;
    for(int j=0;j<26;j++){
      if(cnt[j] != 0){
        target = j;
        cnt[j]--;
        break;
      }
    }
    while(idx<n && s[idx] != char(target+'a')){
      cnt[s[idx]-'a']--;
      idx++;
    }
    ans += s[idx];
    idx++;
    cnt[s[n-k+i+1]-'a']++;
  }
  cout << ans << endl;
  return 0;
}

