#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  string s;
  cin >> s;
  int fr = 0;
  while(fr < s.size() && s[fr] == 'a') fr++;
  int bc = s.size()-1;
  while(bc>=0 && s[bc] == 'a') bc--;
  if(fr > s.size()-bc-1){
    cout << "No" << endl;
    return 0;
  }
  while(s.size() != 0 && s.back() == 'a') s.pop_back();
  if(s.size() == 0){
    cout << "Yes" << endl;
    return 0;
  }
  string ns ="";
  int cnt = 0;
  while(cnt<s.size() && s[cnt] == 'a') cnt++;
  for(int i=cnt;i<s.size();i++) ns+=s[i];
  string t = ns;
  reverse(t.begin(),t.end());
  if(t==ns) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

