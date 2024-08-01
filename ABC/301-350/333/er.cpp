#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  vector<P> events(n);
  for(int i=0;i<n;++i) cin >> events[i].first >> events[i].second;
  vector<int> add;
  multiset<int> need;
  int kmin = -1;
  for(int i=n-1;i>=0;i--){
    if(events[i].first == 1){
      if(need.count(events[i].second)){
         add.push_back(1);
         auto it = need.find(events[i].second);
         need.erase(it);
       }
      else add.push_back(0);
    }else{
      need.insert(events[i].second);
    }
    kmin = max(kmin,(int)need.size());
  }
  if(need.size() > 0){
    cout << -1 << endl;
    return 0;
  }else{
    cout << kmin << endl;
    for(int i=add.size()-1;i>=0;i--) cout << add[i] << ' '; cout << endl;
  }
  return 0;
}

