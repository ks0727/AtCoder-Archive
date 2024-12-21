#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(){
  int n,x,k;
  cin >> n >> x >> k;
  vector<pair<long long,set<int> > > dp(x+1);
  dp[0].first = 0;
  dp[0].second = {};
  for(int i=0;i<n;i++){
    vector<pair<long long,set<int> > > old = dp;
    long long p,u,c;
    cin >> p >> u >> c;
    for(int j=0;j<=x;j++){
      if(j-p<0) continue;
      long long add = u;
      if(!old[j-p].second.count(c)) add += k;
      if(old[j-p].first+add > dp[j].first){
        dp[j].first = old[j-p].first + add;
        if(!old[j-p].second.count(c)){
          set<int> st = old[j-p].second;
          st.insert(c);
          dp[j].second = st;
        }else{
          dp[j].second = old[j-p].second;
        }
      }
    }
  }
  cout << dp[x].first << endl; 
  return 0;
}

