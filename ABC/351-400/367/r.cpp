#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> r(n);
  vector<vector<int> >ans;
  for(int i=0;i<n;i++) cin >> r[i];
  auto f = [&](auto f,vector<int> now)->void{
    if(now.size() == n){
      int sum = 0;
      for(int i=0;i<n;i++) sum += now[i];
      if(sum%k ==0) ans.push_back(now);
      return;
    }
    int d=now.size();
    for(int i=0;i<r[d];i++){
      now.push_back(i+1);
      f(f,now);
      now.pop_back();
    }
  };
  f(f,vector<int>{});
  sort(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<n;j++) cout << ans[i][j] << ' '; cout << endl;
  }
}
