#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  for(int i=0;i<n;i++){
    string now = "";
    for(int j=0;j<3;j++) if(i+j<n) now += s[i+j];
    if(now == "ABC") ans++;
  }
  cout << ans << endl;
  return 0;
}

