#include <iostream>
using namespace std;

int main(){
  double a,b;
  cin >> a >> b;
  double c = a/b;
  string s = to_string(c);
  string ten = "";
  bool carry = false;
  for(int i=0;i<s.size();i++){
    if(s[i] == '.'){
      if((s[i+1]-'0') >= 5) carry = true;
      break;
    }
    ten += s[i];
  }
  int ans = stoi(ten);
  if(carry) ans++;
  cout << ans << endl;
  return 0;
}

