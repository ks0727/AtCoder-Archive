#include <iostream>
using namespace std;

int main(){
  string t = "";
  string temp = "oxx";
  string s;
  cin >> s;
  for(int i=0;i<10;i++) t += temp;
  for(int i=0;i<3;i++){
    if(t.substr(i,s.size()) == s){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}

