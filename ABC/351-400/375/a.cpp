#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  for(int i=0;i<n-2;i++){
    if(s[i] == '#' && s[i+2] == '#' && s[i+1] == '.') ans++;
  }
  cout << ans << endl;
  return 0;
}

