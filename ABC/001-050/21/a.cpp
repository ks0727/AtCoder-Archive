#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  int now = 8;
  vector<int> ans;
  while(n){
    for(int i=0;i<n/now;i++) ans.push_back(now);
    n %= now;
    now /= 2;
  }
  cout << ans.size() << endl;
  for(int i=0;i<ans.size();i++) cout << ans[i] << endl;
  return 0;
}

