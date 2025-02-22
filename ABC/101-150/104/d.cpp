#include <iostream>
#include<vector>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  int asum=0,csum=0,hsum=0;
  for(int i=0;i<n;i++){
    if(s[i] == 'A') asum++;
    else if(s[i] == 'C') csum++;
    else if(s[i] == '?') hsum++;
  }
  int acnt=0,ccnt=0,hcnt=0;
  mint ans = 0;
  for(int i=0;i<n;i++){
    if(s[i] == 'A') acnt++;
    else if(s[i] == 'C') ccnt++;
    else if(s[i] == '?') hcnt++;
    else{
      mint now = (mint)(acnt+hcnt)*(csum-ccnt+hsum-hcnt);
      ans += now;
    }
  }
  cout << ans.val() << endl;
  return 0;
}

