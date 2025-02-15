#include <iostream>
#include<algorithm>
using namespace std;

bool ispalind(string x){
  string y = x;
  reverse(y.begin(),y.end());
  return x == y;
}
int main(){
  string s;
  cin >> s;
  int n = s.size();
  string s1 = s.substr(0,n/2);
  string s2 = s.substr(n/2+1,n/2);
  if(ispalind(s) && ispalind(s1) && ispalind(s2) ) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

