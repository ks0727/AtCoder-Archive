#include <iostream>
using namespace std;

int main(){
  int k;
  cin >> k;
  string s;
  cin >> s;
  if(s.size() <= k) cout << s << endl;
  else{
    string t = s.substr(0,k);
    cout << t << "..." << endl;
  }
  return 0;
}

