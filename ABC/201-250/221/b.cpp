#include <iostream>
using namespace std;

int main(){
  string s,t;
  cin >> s >> t;
  if(s == t){
    cout << "Yes" << endl;
    return 0;
  }
  for(int i=0;i<s.size()-1;i++){
    string ns = s;
    swap(ns[i],ns[i+1]);
    if(ns == t){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}

