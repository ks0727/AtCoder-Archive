#include <iostream>
using namespace std;

int main(){
  string s;
  cin >> s;
  int ans = 0;
  int min = 0;
  for(int i=s.size()-1;i>=0;i--){
    int now = s[i] - '0' + 1e9 - min;
    now %= 10;
    ans += now + 1;
    min += now;
  }
  cout << ans << endl;
  return 0;
}

