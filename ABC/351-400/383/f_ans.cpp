#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll= long long;

void chmax(ll &x, ll y){x = max(x,y);}
int main(){
  int n,x,k;
  cin >>n >> x >> k;
  vector<tuple<int,int,int> > items;
  for(int i=0;i<n;i++){
    int p,u,c;
    cin >> p >> u >> c;
    items.emplace_back(c,p,u);
  }
  sort(items.begin(),items.end());
  vector<vector<ll> > dp(x+1,vector<ll>(2));
  int pre_c = -1;
  for(auto [c,p,u] : items){
    if(pre_c != c){ //色が変わったら使用した情報をreset
      for(int i=0;i<=x;i++){
        chmax(dp[i][0],dp[i][1]);
      }
      pre_c = c;
    }
    vector<vector<ll> > old(x+1,vector<ll>(2));
    swap(old,dp);
    for(int i=0;i<=x;i++){
      for(int j=0;j<2;j++) chmax(dp[i][j],old[i][j];
      int ni = i+p;
      if(ni <= x) {
        chmax(dp[ni][1],old[i][1]+u);
        chmax(dp[ni][1],old[i][0]+u+k);
      }
    }
  }
  ll ans = dp[x][1];
  cout << ans << endl;
  return 0;
}

