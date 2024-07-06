#include <iostream>
using namespace std;

int main(){
  string s;
  cin >> s;
  if(s =="a") {
    cout << -1 << endl;
    return 0;
  }

  for(int i=0;i<s.size();i++){
    if(s[i] != 'a'){
      s[i] ='a';
      break;
    }
  }
  if(s.size() > 1) s.pop_back();
  cout << s << endl;
  return 0;
}

