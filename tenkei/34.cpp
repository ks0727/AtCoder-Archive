#include <iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  int r = 0;
  map<int,int> mp;
  int ans = 0;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int l=0;l<n;l++){
    while(r < n){
        if(mp.find(a[r]) == mp.end()  && mp.size() == k) break;
        mp[a[r]]++;
        r++;
    }
    ans = max(ans,r-l);
    mp[a[l]]--;
    if(mp[a[l]]== 0) mp.erase(a[l]);
  }
  cout << ans << endl;
  return 0;
}

