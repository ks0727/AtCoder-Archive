#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> c(9);
  for(int i=0;i<9;i++) cin >> c[i];
  vector<string> dp(n+1,"");
  dp[0] = "0";
  for(int i=0;i<n+1;i++){
    vector<pair<string,int> > ss;
    for(int j=0;j<9;j++){
      if(i-c[j] >=0 && dp[i-c[j]] != "") {
        ss.emplace_back(dp[i-c[j]],j);
      }
    }
    if(ss.size() != 0){
      sort(ss.rbegin(),ss.rend());
      //for(auto [t,num] : ss) cout << t << ' '; cout << endl;
      auto [t,num] = ss[0];
      dp[i] = t+char(num+'1');
    }
  }
  vector<string> ans;
  for(int i=0;i<n+1;i++){
    if(dp[i] == "") continue;
    else{
      ans.push_back(dp[i].substr(1));
    }
  }
  sort(ans.rbegin(),ans.rend());
  cout << ans[0] << endl;
}

