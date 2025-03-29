#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  if(n%2==1) return 0;
  vector<string> ans;
  for(int bit=0;bit<1<<n;bit++){
    int cnt = 0;
    bool ok = true;
    for(int i=0;i<n;i++){
      if(bit>>i&1) cnt++;
      if((i+1)-cnt > cnt){
        ok = false;
        break;
      }
    }
    if(cnt != n/2) ok = false;
    if(ok){
      string s = "";
      for(int i=0;i<n;i++){
        if(bit>>i&1) s += '(';
        else s += ')';
      }
      ans.push_back(s);
    }
  }
  sort(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++) cout << ans[i] << endl;
  return 0;
}

