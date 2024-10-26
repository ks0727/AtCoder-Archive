#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  if(n >= 42) n++;
  string s = to_string(n);
  if(s.size() < 3){
    reverse(s.begin(),s.end());
    while(s.size() < 3) s += '0';
  }
  reverse(s.begin(),s.end());
  string ans = "AGC"+s;
  cout << ans << endl;
  return 0;
}

