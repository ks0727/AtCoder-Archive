#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> b(n-1);
  for(int i=0;i<n-1;i++) cin >> b[i];
  int ans = 0;
  int prev = b[0];
  for(int i=0;i<n-1;i++){
    ans += min(prev,b[i]);
    prev = b[i];
  }
  cout << ans+b[n-2] << endl;
  return 0;
}

