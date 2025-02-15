#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int,int>;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a.rbegin(),a.rend());
  priority_queue<P,vector<P> > q;
  q.emplace(a[0],1);
  for(int i=1;i<n;i++) q.emplace(a[i],2);
  long long ans = 0;
  for(int i=0;i<n-1;i++){
    auto [val,cnt] = q.top(); q.pop();
    ans += val;
    cnt--;
    if(cnt == 1) q.emplace(val,cnt);
  }
  cout << ans << endl;
  return 0;
}

