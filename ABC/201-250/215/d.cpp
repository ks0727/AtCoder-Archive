#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  set<int> st;
  for(int i=0;i<n;i++){
    for(int j=2;j*j<=a[i];j++){
     if(a[i]%j != 0) continue;
     while(a[i]%j == 0) a[i] /= j;
     st.insert(j);
    }
    if(a[i] != 1) st.insert(a[i]);
  }
  vector<int> ok(m+1,true);
  for(int x : st){
    for(int j=x;j<=m;j+=x) ok[j] = false;
  }
  vector<int> ans;
  for(int i=1;i<=m;i++) if(ok[i]) ans.push_back(i);
  cout << ans.size() << endl;
  for(int i=0;i<ans.size();i++) cout << ans[i] << endl;
}

