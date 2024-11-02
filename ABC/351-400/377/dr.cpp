#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<int,int> > ps;
  vector<int> lmx(m+1);
  for(int i=0;i<n;i++){
    int l,r;
    cin >> l >> r;
    lmx[r] = max(lmx[r],l);
  }
  sort(ps.begin(),ps.end());
  int l = 1;
  int idx = 0;
  long long ans = 0;
  for(int r=1;r<=m;r++){
    l = max(l,lmx[r]+1);
    ans += r-l+1;
  }
  cout << ans << endl;
  return 0;
}

