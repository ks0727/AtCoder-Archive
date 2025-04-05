#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cin >> b[i];
  int dif = 0;
  for(int i=0;i<n;i++){
    if(a[i] != b[i]) dif += abs(a[i]-b[i]);
  }
  if(dif > k){
    cout << "No" << endl;
    return 0;
  }else dif -= k;
  if(dif%2 == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

