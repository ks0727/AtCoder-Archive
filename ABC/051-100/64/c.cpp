#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<int> cnt(13);
  int over = 0;
  for(int i=0;i<n;i++){
    cnt[a[i]/400]++;
    if(a[i] >= 3200) over++;
  }
  int ans = 0;
  for(int i=0;i<8;i++) if(cnt[i]>0) ans++;
  cout << max(1,ans) << ' ' << ans+over << endl;
  return 0;
}

