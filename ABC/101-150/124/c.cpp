#include <iostream>
#include<algorithm>
using namespace std;

int main(){
  string s;
  cin >> s;
  int ans = 1001001001;
  for(int k=0;k<2;k++){
    char target = k==0?'0':'1';  
    int now = 0;
    for(int i=0;i<s.size();i++){
      if(i%2 == 0 && s[i] != target) now++;
      else if(i%2 == 1 && s[i] == target) now++;
    }
    ans = min(ans,now);
  }
  cout << ans << endl;
  return 0;
}

