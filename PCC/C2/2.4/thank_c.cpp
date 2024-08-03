#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<ll,int>;
ll a[1<<17],b[1<<17];
int main(){
  int n,k;
  cin >> n >> k;
  priority_queue<P,vector<P>,greater<P> > q;
  for(int i=0;i<n;i++){
     cin >> a[i] >> b[i];
     q.push(P(a[i],i));
  }
  int cnt = 0;
  ll ans = 0;
  while(cnt < k){
    auto [t,i] = q.top(); q.pop();
    ans += t;
    q.push(P(t+b[i],i));
    cnt++;
  }
  cout << ans << endl;
  return 0;
}

