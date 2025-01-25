#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int left=n+1,right=-1;
  for(int i=0;i<n;i++){
    if(s[i] == '|'){
      left = i;
      break;
    }
  }
  for(int i=n-1;i>=0;i--){
    if(s[i] == '|'){
      right = i;
      break;
    }
  }
  int x = -1;
  for(int i=0;i<n;i++){
    if(s[i] == '*') x = i;
  }
  if(left < x && x < right) cout << "in" << endl;
  else cout << "out" << endl;
  return 0;
}

