#include <iostream>
using namespace std;

int main(){
  string s;
  cin >> s;
  int prev = -1;
  for(int i=0;i<s.size();i++){
    if(s[i] == '.') continue;
    if(prev == -1) prev = i;
    else{
      cout << prev+1 << ',' << i+1 << endl;
      prev = -1;
    }
  }
  return 0;
}

