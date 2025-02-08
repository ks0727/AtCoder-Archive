#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  for(int i=0;i<n;i++) cin >> p[i];
  int mn = 1001001001;
  int ans = 0;
  for(int i=0;i<n;i++){
    if(p[i] < mn){
      ans++;
      mn = p[i];
    }
  }
  cout << ans << endl;
  return 0;
}

