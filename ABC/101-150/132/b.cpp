#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  int ans = 0;
  for(int i=0;i<n;i++) cin >> p[i];
  for(int i=1;i<n-1;i++){
    vector<int> now;
    now.push_back(p[i-1]);
    now.push_back(p[i]);
    now.push_back(p[i+1]);
    sort(now.begin(),now.end());
    if(now[1] == p[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}

