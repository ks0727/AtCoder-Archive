#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int p=0;
  int cnt = 0;
  for(int i=0;i<n;i++){
    if(p == 0 && s[i] == ')') cnt++;
    else if(s[i] == ')'){
      p--;
    }else{
      p++;
    }
  }
  string ans = "";
  for(int i=0;i<cnt;i++) ans += '(';
  for(int i=0;i<n;i++) ans += s[i];
  for(int i=0;i<p;i++) ans += ')';
  cout << ans << endl;
  return 0;
}

