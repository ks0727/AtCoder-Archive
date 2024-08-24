#include <iostream>
#include <algorithm>
using namespace std;
int ds[1<<17];
int rs[1<<17];
int k[10000];

int main(){
  int d;
  cin >> d;
  int n;
  cin >> n;
  int m;
  cin >> m;
  for(int i=1;i<n;i++) cin >> ds[i];
  for(int i=0;i<m;++i) cin >> k[i];
  
  sort(ds,ds+n);
  for(int i=1;i<n;i++) rs[i] = d - ds[i];
  sort(rs,rs+n);

  int ans = 0;
  for(int i=0;i<m;++i){
    int now = 1001001001;
    int x = k[i];
    int lb = upper_bound(ds,ds+n,x) - ds;
    if(lb == n) now = min(now,x-ds[n-1]);
    else{
      now = min(now,abs(x-ds[lb]));
      now = min(now,abs(x-ds[lb-1]));
    }
    int lb2 = upper_bound(rs,rs+n,d-x) - rs;
    if(lb2 == n) now = min(now,d-x-rs[n]);
    else{
      now = min(now,abs(d-x-rs[lb2]));
      now = min(now,abs(d-x-rs[lb2-1]));
   }
   ans += now;
 }
 cout << ans << endl;
  return 0;
}

