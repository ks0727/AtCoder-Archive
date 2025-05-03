#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  bool login = false;
  int ans = 0;
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    if(s == "login") login = true;
    else if(s == "logout") login = false;
    else if(s == "public" ) continue;
    else if(s == "private"){
      if(!login) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

