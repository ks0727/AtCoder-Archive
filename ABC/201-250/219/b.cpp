#include <iostream>
using namespace std;
string s[3];
int main(){
  for(int i=0;i<3;i++) cin >> s[i];
  string t;
  cin >> t;
  for(int i=0;i<t.size();i++){
    int idx = t[i]-'0'-1;
    cout << s[idx];
  }
  cout << endl;
  return 0;
}

