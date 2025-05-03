#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  while(q--){
    long long k;
    cin >> k;
    long long num = upper_bound(a.begin(),a.end(),k) - a.begin();
    cout << k + num << endl;
  }
  return 0;
}

