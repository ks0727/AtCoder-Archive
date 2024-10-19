#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  long long k;
  cin >> k;
  string ans = "";
  for(int i=0;i<61;i++){
    if(k>>i&1) ans += '2';
    else ans += '0';
  }
  while(ans.back() == '0') ans.pop_back();
  reverse(ans.begin(),ans.end());
  cout << ans << endl;
  return 0;
}

