#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  for(int i=0;i<n;i++) cin >> p[i],p[i]--;
  vector<int> ans(n);
  for(int i=0;i<n;i++){
    ans[p[i]] = i;
  }
  for(int i=0;i<n;i++) cout << ans[i]+1 << ' '; cout << endl;
  return 0;
}

