#include <iostream>
using namespace std;

int main(){
  string s,t;
  cin >> s >> t;
  bool fit = false;
  for(int i=s.size()-t.size();i>=0;i--){
    string ns = s.substr(i,t.size());
    for(int j=0;j<ns.size();j++){
      if(ns[j] != '?' && ns[j] != t[j]) break;
      if(j == ns.size()-1) fit = true;
    }
    if(!fit) continue;
    for(int j=0;j<t.size();j++){
      s[i+j] = t[j];
    }
    break;
  }
  if(!fit){
    cout << "UNRESTORABLE"<< endl;
    return 0;
  }else{
    for(int i=0;i<s.size();++i){
      if(s[i] == '?') s[i] = 'a';
    }
    cout << s << endl;
  }   
  return 0;
}

