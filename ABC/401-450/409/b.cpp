#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  int ans = 0;
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<=100;i++){
    int cnt = 0;
    for(int j=0;j<n;j++){
      if(a[j] >= i) cnt++;
    }
    if(cnt >= i) ans = i;
  } 
  cout << ans << endl;
  return 0;
}

