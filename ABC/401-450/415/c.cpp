#include <iostream>
#include<vector>
#include<set>
using namespace std;

bool solve(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<bool> dp((1<<(n+1))+1,false);
  dp[0] = true;
  for(int i=0;i<1<<(n+1);i++){
    if(!dp[i]) continue; 
    for(int j=0;j<n;j++){
      int now = i|1<<j;
      if(s[now] == '1') continue;
      dp[now] = true;
    }
  }
  for(int i=0;i<n;i++){
    if(dp[i]) cout << "ok" << ' ';
    else cout << "no" << ' ';
  }
  cout << endl;
  return dp[(1<<(n+1))-1];
}

int main(){
  int t; cin >> t;
  while(t--){
    if(solve()) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}

