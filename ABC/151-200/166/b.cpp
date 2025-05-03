#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n,k;
  cin >> n>> k;
  vector<bool> has(n);
  for(int i=0;i<k;i++){
    int d;
    cin >> d;
    for(int j=0;j<d;j++){
      int a;
      cin >> a;
      a--;
      has[a] = true;
    }
  }
  int ans = 0;
  for(int i=0;i<n;i++) if(!has[i]) ans++;
  cout << ans << endl;
  return 0;
}

