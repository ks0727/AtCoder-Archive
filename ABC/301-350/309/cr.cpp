#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<pair<int,long long> > ps;
  for(int i=0;i<n;i++){
    int a; long long b;
    cin >> a >> b;
    ps.emplace_back(a,b);
  }
  sort(ps.begin(),ps.end());
  long long sum = 0;
  int ans_id = -1;
  for(int i=n-1;i>=0;i--){
    sum += ps[i].second;
    if(sum > k){
      ans_id = i;
      break;
    }
  }
  if(ans_id == -1){
    cout << 1 << endl;
  }else{
    cout << ps[ans_id].first+1 << endl;
  }
  return 0;
}

