#include <iostream>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;

vector<string> rot(vector<string> x){
  vector<string> ret = x;
  int n = x.size();
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      ret[j][n-i-1] = x[i][j];
    }
  }
  return ret;
}
int f(vector<string> x,vector<string> y){
  int ret = 0;
  int n = x.size();
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(x[i][j] != y[i][j]) ret++;
    }
  }
  return ret;
}
int main(){
  int n;
  cin >> n;
  vector<string> s(n),t(n);
  for(int i=0;i<n;i++) cin >> s[i];
  for(int i=0;i<n;i++) cin >> t[i];
  int ans = 1001001001;
  vector<string> now = s;
  for(int i=0;i<4;i++){
    ans = min(ans,i+f(now,t));
    now = rot(now);
  }
  cout << ans << endl;
  return 0;
}

