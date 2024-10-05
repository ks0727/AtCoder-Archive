#include <iostream>
#include <algorithm>
using namespace std;
bool cut[720];
int a[360];
int main(){
  int  n;
  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];
  cut[0] = true;
  int cur = 0;
  for(int i=0;i<n;i++)
  {
    cur += a[i];
    cur %= 360;
    cut[cur] = true;
    cut[cur+360] = true;
  }
  int ans = 0;
  for(int i=0;i<720;i++)
  {
    if(!cut[i]) continue;
    int j = i+1;
    while(j<360 && !cut[j]) j++;
    ans = max(ans,j-i);
  }
  cout << ans << endl; 
  return 0;
}

