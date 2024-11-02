#include <algorithm>
#include <iostream>
#include <vector>
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
  long long now = 0;
  int ans = -1;
  for(int i=n-1;i>=0;i--){
    now += ps[i].second;
    if(now > k){
      ans = n-i-1;
      break;
    }
  }
  if(ans == -1){
    cout << 1 << endl;
  }else{
    cout << ps[ans+1].first << endl;
  }
  return 0;
} 
    

  


