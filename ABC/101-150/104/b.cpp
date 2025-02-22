#include <iostream>
using namespace std;
bool solve(){
  string s;
  cin >> s;
  if(s[0] != 'A') return false;
  int cnt = 0;
  int idx = -1;
  for(int i=2;i<s.size()-1;i++) if(s[i] == 'C'){
    cnt++;
    idx = i;
  }
  if(cnt != 1) return false;
  for(int i=0;i<s.size();i++){
    if(i == 0 || i == idx) continue;
    if('a' > s[i] || s[i] > 'z') return false;
  }
  return true;
}

int main(){
  if(solve()) cout <<"AC" << endl;
  else cout << "WA" << endl;
  return 0;
}

