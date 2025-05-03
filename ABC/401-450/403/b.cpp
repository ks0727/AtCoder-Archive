#include <iostream>
using namespace std;

int main(){
  string t,u;
  cin >> t >> u;
  for(int i=0;i<t.size()-u.size()+1;i++){
    bool ok = true;
    for(int j=0;j<u.size();j++){
      if(t[i+j]=='?') continue;
      if(t[i+j] != u[j]) ok = false;
    }
    if(ok){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}

