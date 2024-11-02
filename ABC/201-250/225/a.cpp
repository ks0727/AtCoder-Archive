#include <iostream>
using namespace std;
int cnt[26];
int main(){
  string s;
  cin >> s;
  for(int i=0;i<3;i++) cnt[s[i]-'a']++;
  int num = 0;
  for(int i=0;i<26;i++) if(cnt[i] != 0) num++;
  if(num == 1){
    cout << 1 << endl;
  }else if(num ==2){
    cout << 3 << endl;
  }else{
    cout << 6 << endl;
  }
  return 0;
}

