#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main()
{ 
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool ok  = true;
  rep(i,n){
    if(s[i] == s[i+1]){
      ok = false;
      break;
    }
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
