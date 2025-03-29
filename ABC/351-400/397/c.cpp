#include <iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<int> f(n),b(n);
  set<int> st1;
  for(int i=0;i<n;i++){
    st1.insert(a[i]);
    f[i] = st1.size();
  }
  set<int> st2;
  for(int i=n-1;i>=0;i--){
    st2.insert(a[i]);
    b[i] = st2.size();
  }
  int ans = 0;
  for(int i=0;i<n-1;i++){
    ans = max(ans,f[i]+b[i+1]);
  }
  cout << ans << endl;
  return 0;
}

