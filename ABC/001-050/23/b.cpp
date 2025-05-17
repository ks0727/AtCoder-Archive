#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  if(n%2 == 0){
    cout << -1 << endl;
    return 0;
  }
  if(s[n/2] != 'b'){
    cout << -1 << endl;
    return 0;
  }
  for(int i=0;i<n/2;i++){
    if((i+1)%3 == 1){
      if(s[n/2-i-1] != 'a' || s[n/2+i+1] != 'c'){
        cout << -1 << endl;
        return 0;
      }
    }else if((i+1)%3 == 2){
      if(s[n/2-i-1] != 'c' || s[n/2+i+1] != 'a'){
        cout << -1 << endl;
        return 0;
      }
    }else{
      if(s[n/2-i-1] != 'b' || s[n/2+i+1] != 'b'){
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << n/2 << endl;
  return 0;
}

