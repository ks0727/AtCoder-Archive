#include <iostream>
#include<vector>
using namespace std;

void solve(){
  int n;
  cin >> n;
  int n2 = n*2; 
  vector<int> a(n2);
  vector<pair<int,int> > ps(n,make_pair(-1,-1));
  for(int i=0;i<n2;i++){
    cin >> a[i]; a[i]--;
    if(ps[a[i]].first == -1) ps[a[i]].first = i;
    else ps[a[i]].second = i;
  }
  int ans = 0;
  for(int i=0;i<n2-1;i++){
    if(i == ps[a[i]].second) continue;
    if(i+1 == ps[a[i+1]].second) continue;
    if(a[i] == a[i+1]) continue;
    int u = ps[a[i]].second;
    int v = ps[a[i+1]].second;
    if(v == u-1 || v == u + 1){
      if(v == i+2) continue;
      ans++;
    }
  }
  cout << ans << endl;
}
    
  
int main(){
  int t;
  cin >> t;
  for(;t--;) solve();
  return 0;
}

