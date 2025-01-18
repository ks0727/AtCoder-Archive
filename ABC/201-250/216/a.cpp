#include <iostream>
using namespace std;

int main(){
  string s;
  cin >> s;
  int x=-1,y=-1;
  y = s.back()-'0';
  s.pop_back();
  s.pop_back();
  if(y<=2) cout << s+'-' << endl;
  else if(y<=6) cout << s << endl;
  else cout << s+'+' << endl;
  return 0;
}

