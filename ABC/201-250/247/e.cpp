#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main(){
  int n,x,y;
  cin >> n >> x >> y;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<bool> bd(n+1);
  const int INF = 1001001001;
  ll ans = 0;
  bd[0] = true;
  for(int i=0;i<n;i++)  if(a[i] > x || a[i] < y) bd[i+1] = true;
  for(int l=0;l<n;l++){
    if(!bd[l]) continue;
    int r = l;
    int xi = -1,yi = -1;
    while(r < n && !bd[r+1]){
      if(a[r] == x) xi = max(r+1,xi);
      if(a[r] == y) yi = max(r+1,yi);
      if(yi > xi && xi != -1) ans += (xi-l);
      else if(xi > yi && yi != -1) ans += (yi-l);
      else if(xi == yi && yi != -1) ans += (yi-l);
      r++;
    }
    l = r;
  }
  cout << ans << endl;
}


  
