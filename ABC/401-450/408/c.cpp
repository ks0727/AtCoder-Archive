#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> cnt(n+1);
  for(int i=0;i<m;i++){
    int l,r;
    cin >> l >> r;
    l--;
    cnt[l]++; cnt[r]--;
  }
  for(int i=0;i<n;i++) cnt[i+1] += cnt[i];
  int ans = 1001001001;
  for(int i=0;i<n;i++) ans = min(ans,cnt[i]);
  cout << ans << endl;
  return 0;
}

