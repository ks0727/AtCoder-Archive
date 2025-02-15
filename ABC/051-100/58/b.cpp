#include <iostream>
using namespace std;

int main(){
  string s,t;
  cin >>s >> t;
  int n = s.size();
  for(int i=0;i<n;i++){
    cout << s[i];
    if(i<t.size()) cout << t[i];
  }
  cout << endl;
  return 0;
}

