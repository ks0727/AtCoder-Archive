#include <iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  set<int> st;
  vector<int> cnt(n+1);
  for(int i=0;i<=n;i++) st.insert(i);
  for(int i=0;i<n;i++){
    if(a[i] <= n) cnt[a[i]]++;
    if(st.count(a[i])) st.erase(a[i]);
  }
  int mex = *st.begin();
  while(q--){
    int id,x;
    cin >> id >> x;
    id--;
    int now = a[id];
    if(now <= n){
      cnt[now]--;
      if(cnt[now] == 0){
        st.insert(now);
      }
    }
    if(x <= n && cnt[x] == 0){
        st.erase(x);
    }
    if(x <= n) cnt[x]++;
    a[id] = x;
    cout << *st.begin() << endl;
  }
}



