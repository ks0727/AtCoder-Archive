#include <iostream>
using namespace std;
int cnt[10];
int main(){
  string s;
  cin >> s;
  for(char c : s) cnt[c-'0']++;
  for(int i=0;i<10;i++) if(cnt[i]==0) cout << i << endl;
  return 0;
}

