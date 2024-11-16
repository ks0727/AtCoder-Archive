#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
using P = pair<int,int>;
void solve(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cin >> b[i];
  vector<bool> usable(n,true);
  vector<P> pa,pb;
  for(int i=0;i<n;i++){
    pa.emplace_back(a[i],i);
    pb.emplace_back(b[i],i);
  }
  sort(pa.rbegin(),pa.rend());
  sort(pb.begin(),pb.end());
  long long bnow = 0;
  long long ans = 1e18;
  set<int> st;
  for(int i=0;i<k;i++){
     bnow += pb[i].first;
     st.insert(pb[i].second);
  }
  int current = k-1;
  for(int i=0;i<n-k+1;i++){
    long long anow = pa[i].first;
    int idx = pa[i].second; //idxは絶対に使う必要がある
    usable[pa[i].second] = false; //それ以降使えなくなる
    if(st.count(idx)){ //すでに使っている時 
      ans = min(ans,anow*bnow);
      bnow -= b[idx];
      st.erase(idx);
      while(!usable[current]) current++;
      st.insert(current);
      bnow += pb[current].first;
    }else{//使っていない時
      long long nb = bnow;
      nb += b[idx];
      nb -= pb[current].first;
      ans = min(ans,nb*anow);
    }
  }
  cout << ans << '\n';
}
    
int main(){
  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}

