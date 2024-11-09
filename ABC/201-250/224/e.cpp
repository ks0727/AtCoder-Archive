#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int h,w,n;
  cin >> h >> w >> n;
  vector<vector<pair<int,int> > > rows(h),cols(w);
  vector<int> r(n),c(n),a(n);
  for(int i=0;i<n;i++){
    cin >> r[i] >> c[i] >> a[i];
    r[i]--; c[i]--;
    rows[r[i]].emplace_back(a[i],i);
    cols[c[i]].emplace_back(a[i],i);
  }
  for(auto arr : rows){
    for(int i=0;i<arr.size()-1;i++){
      auto [val,idx] = arr[i];

  return 0;
}

