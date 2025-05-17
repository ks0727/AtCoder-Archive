#include <iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int r,c,k;
  cin >> r >> c >> k;
  int n;
  cin >> n;
  vector<int> cntr(r),cntc(c);
  set<pair<int,int> > st;
  for(int i=0;i<n;i++){
    int ri,ci;
    cin >> ri >> ci;
    ri--; ci--;
    st.emplace(ri,ci);
    cntr[ri]++;
    cntc[ci]++;
  }
  long long ans = 0;
  for(auto [ri,ci] : st){
    if(cntr[ri] + cntc[ci] == k+1) ans++;
    else if(cntr[ri] + cntc[ci] == k) ans--;
  }
  sort(cntr.begin(),cntr.end());
  sort(cntc.begin(),cntc.end());
  for(int i=0;i<r;i++){
    int now = cntr[i];
    int rest = k-now;
    if(rest < 0 ) break;
    long long add = upper_bound(cntc.begin(),cntc.end(),rest) - lower_bound(cntc.begin(),cntc.end(),rest);
    ans += add;
  }
  cout << ans << endl;
  return 0;
}

