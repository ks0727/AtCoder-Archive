#include <iostream>
using namespace std;

int main(){
  string s,t;
  cin >> s >> t;
  for(int i=1;i<s.size();i++){
    if('A' <= s[i] && s[i] <= 'Z'){
      char now = s[i-1];
      for(int j=0;j<t.size();j++){
        if(t[j] == now) break;
        if(j == t.size()-1){
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}

