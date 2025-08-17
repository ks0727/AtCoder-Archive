#include <iostream>
using namespace std;

int main(){
  int n,a,b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  string ans = "";
  for(int i=a-1;i<b;i++){
    ans += s[i];
  }
  cout << ans << endl;
  return 0;
}

