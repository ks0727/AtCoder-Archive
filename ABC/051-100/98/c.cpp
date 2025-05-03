#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int lcnt= 0, rcnt=0;
  for(int i=n-1;i>=0;i--) if(s[i] == 'E') rcnt++;
  int ans = 1001001001;
  for(int i=0;i<n;i++){
    if(s[i] == 'E') rcnt--;
    ans = min(ans,lcnt+rcnt);
    if(s[i] == 'W') lcnt++;
  }
  cout << ans << endl;
  return 0;
}

