#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using P = pair<int,int>;

int main(){
  int n,m,h,k;
  cin >> n >> m >> h >> k;
  vector<int> p(n);
  for(int i=0;i<n;i++) cin >> p[i];
  vector<P> bs;
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--;
    bs.emplace_back(b,a);
  }
  sort(bs.begin(),bs.end());
  vector<P> vs(m);
  vector<P> ps(m);
  vector<int> to(n);
  for(int i=0;i<n;i++) to[i] = i;
  for(int i=0;i<m;i++){
    auto [b,a] = bs[i];
    vs[i] = P(to[a],to[a+1]);
    swap(to[a],to[a+1]);
  }
  for(int i=m-1;i>=0;i--){
    auto [b,a] = bs[i];
    ps[i] = P(p[a],p[a+1]);
    swap(p[a],p[a+1]);
  }
  int ans = 0;
  for(int i=0;i<k;i++) ans += p[i];
  int diff = 0;
  for(int i=0;i<m;i++){
   auto [v,u] = vs[i];
   if(0 <= v && v < k && 0 <= u && u < k) continue;
   if(v >= k && u >= k) continue; 
   //uとvのどちらかがk以上でどちらかがkより小さい
   int pa = ps[i].first; int pb = ps[i].second;
   if(v > u){
     swap(u,v);
     swap(pa,pb);
   }
   //vは含む, uは含まない
   if(pa< pb) diff = min(diff,pa-pb);
 }
  ans += diff;
  cout << ans << endl;
  return 0;
}
