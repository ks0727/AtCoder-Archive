#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int> > idx(n);
  for(int i=0;i<n;i++){
    int x,c;
    cin >> x >> c;
    c--;
    idx[c].push_back(x);
  }
  for(int i=0;i<n;i++) sort(idx[i].begin(),idx[i].end());
  int prev = 0;
  long long ans = 0;
  for(int i=0;i<n;i++){
    cout << prev << endl;
    if(idx[i].size() == 0) continue;
    if(idx[i].size() == 1){
      ans += abs(prev - idx[i][0]);
      prev = idx[i][0];
    }else{
      int l = idx[i][0]; int r = idx[i].back();
      if(abs(prev - l) >= abs(prev-r)){
        ans += abs(prev-r);
        ans += r-l;
        prev = l;
      }
    }
  }
  ans += abs(prev);
  cout << ans << endl;
  return 0;
}

