#include <iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> c(n),a(n);
  for(int i=1;i<=n-1;i++) cin >> c[i];
  for(int i=1;i<=n-1;i++) cin >> a[i];
  int sum = 0;
  for(int i=0;i<n;i++) sum += a[i];
  queue<vector<int> > q;
  q.push(a);
  map<vector<int>,int> mp;
  mp[a] = 0;
  while(!q.empty()){
    vector<int> v = q.front(); q.pop();
    int nl = 0;
    vector<int> nxt = v;
    for(int i=n-1;i>=1;i--){
      if(v[i] != 0){
        nl = i;
        break;
      }
    }
    for(int i=1;i<=c[nl];i++){
      nxt[max(0,nl-i)] += v[nl];
      nxt[nl] = 0;
      if(!mp.count(nxt)) mp[nxt] = mp[v]+1;
      else{
        mp[nxt] = min(mp[nxt],mp[v]+1);
      }
      q.push(nxt);
      nxt[max(0,nl-i)] -= v[nl];
      nxt[nl] = v[nl];
    }
  }
  vector<int> ans(n);
  ans[0] = sum;
  cout << mp[ans] << endl;
  return 0;
}

