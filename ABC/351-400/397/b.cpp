#include <iostream>
using namespace std;

int main(){
  string s;
  cin >> s;
  int add = 0;
  int n = s.size();
  for(int i=0;i<n-1;i++){
    if(s[i]==s[i+1]) add++;
  }
  int len=add+s.size();
  if(len%2 == 1) add++;
  else if(s[0] == 'o') add+=2;
  cout << add << endl;
  return 0;
}

