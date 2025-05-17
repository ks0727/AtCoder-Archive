#include <iostream>
#include<vector>  
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  long long s = 0;
  for(int i=0;i<n;i++) s += a[i];
  s *= s;
  long long t = 0;
  for(int i=0;i<n;i++) t += a[i]*a[i];
  long long ans = s - t;
  cout << ans/2 << endl;
  return 0;
}

