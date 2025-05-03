#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n,m,x; cin >> n >> m >> x;
  vector<bool> exists(n+2);
  for(int i=0;i<m;i++){
    int a;
    cin >> a;
    exists[a] = true;
  }
  int ans = 1e9;
  int now1 = 0;
  for(int i=x;i<=n;i++){
    if(exists[i]) now1++;
  }
  ans = min(ans,now1);
  now1 = 0;
  for(int i=x;i>=0;i--){
    if(exists[i]) now1++;
  }
  ans = min(ans,now1);
  cout << ans << endl; 
  return 0;
}

