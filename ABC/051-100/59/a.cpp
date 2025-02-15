#include <iostream>
using namespace std;

int main(){
  string s1,s2,s3;
  cin >> s1 >> s2 >> s3;
  string ans = "";
  ans += s1[0];
  ans += s2[0];
  ans += s3[0];
  for(int i=0;i<3;i++) ans[i] = ans[i]-'a'+'A';
  cout << ans << endl;
  return 0;
}

