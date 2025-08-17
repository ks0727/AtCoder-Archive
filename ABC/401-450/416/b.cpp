#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  string t = s;
  string l = s;
  bool can = true;
  for(int i=0;i<n;i++){
    if(t[i] == '.' && can){
      t[i] = 'o';
      can = false;
    }else if(t[i] == '#'){
      can = true;
    }
  }
  can = true;
  for(int i=n-1;i>=0;i--){
    if(l[i] == '.' && !can){
      can = false;
      l[i] = 'o';
    }else if(l[i] == '#'){
      can = true;
    }
  }
  int cnt1 = 0,cnt2 = 0;
  for(int i=0;i<n;i++){
    if(t[i] == 'o') cnt1++;
    if(l[i] == 'p') cnt2++;
  }
  if(cnt1 > cnt2) cout << t << endl;
  else cout << l << endl;
  return 0;
}

