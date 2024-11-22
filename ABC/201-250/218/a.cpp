#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  n--;
  string s; cin >> s;
  if(s[n] == 'o') cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

