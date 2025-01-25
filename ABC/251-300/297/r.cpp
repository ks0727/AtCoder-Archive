#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a.begin(),a.end());

  priority_queue<long long,vector<long long>, greater<long long> > q;
  for(int i=0;i<n;i++) q.push(a[i]);
  set<long long> st;
  while(k){
    long long v = q.top(); q.pop();
    if(!st.count(v)) k--;
    cout << k << endl;
    st.insert(v);
    if(k == 0){
      cout << v << endl;
      return 0;
    }
    for(int i=0;i<n;i++) q.push(v+a[i]);
  }
}
  

