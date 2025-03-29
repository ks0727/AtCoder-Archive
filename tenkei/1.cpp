#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n,L;
  cin >> n >> L;
  int k;
  cin >> k;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<int> dif(n);
  int cur = 0;
  for(int i=0;i<n;i++){
    dif[i] = a[i] - cur;
    cur = a[i];
  }
  dif.push_back(L-cur);
  n++;
  int l=0, r=L;
  while(r-l>1){
    int m = (l+r)/2;
    int now = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
      if(now >= m){
        now = dif[i];
        cnt++;
      }else{
        now += dif[i];
      }
    }
    if(now >= m) cnt++;
    if(cnt >= k+1) l = m;
    else r=m;
  }
  cout << l << endl;
  return 0;
}

