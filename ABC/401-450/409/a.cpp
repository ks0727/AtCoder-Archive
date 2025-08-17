#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s,t;
  cin >> s >> t;
  for(int i=0;i<n;i++){
    if(s[i] == 'o' && t[i] == 'o'){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}

