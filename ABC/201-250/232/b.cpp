#include <iostream>
#include <map>
using namespace std;

int main(){
  string s,t;
  cin >> s >> t;
  string alpha = "";
  for(int i=0;i<26;i++) alpha += 'a'+i;
  for(int i=0;i<26;i++){
    string ns = "";
    for(int j=0;j<s.size();j++){
      ns += alpha[(s[j]+i)%26];
    }
    if(ns == t){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}

