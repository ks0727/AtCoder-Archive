#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++) cin >> a[i] >> b[i];
  int ans = 1001001001;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int now = 0;
      if(i==j) now = a[i]+b[j];
      else now = max(a[i],b[j]);
      ans = min(ans,now);
    }
  }
  cout << ans << endl;
  return 0;
}

