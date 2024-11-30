#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> p(n);
  long long ans = 0;
  for(int i=0;i<n;i++) cin >> p[i],ans += p[i];
  vector<pair<int,int> > cs(m);
  for(int i=0;i<m;i++) cin >> cs[i].first;
  for(int i=0;i<m;i++) cin >> cs[i].second,cs[i].second *= -1;
  sort(p.begin(),p.end());
  sort(cs.begin(),cs.end());
  int k = 0;
  for(int i=0;i<n;i++){
    if(k < m && p[i] >= cs[k].first){
      ans += cs[k].second;
      k++;
    }
  }
  cout << ans << endl;
}


