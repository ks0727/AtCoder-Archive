#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  long long ans = 0;
  vector<long long> s(n+1);
  for(int i=0;i<n;i++) s[i+1] = s[i]^a[i];
  for(int k=0;k<32;k++){
    long long odd = 0, even = 0;
    for(int i=0;i<n+1;i++){
      if((s[i]>>k)&1){
        odd++;
        swap(even,odd);
      }else{
        even++;
      }
    }
   ans += odd*(1LL<<k);
  }
  cout << ans << endl;
}


