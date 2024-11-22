#include <iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  set<pair<int,int> > st;
  vector<pair<int,int> > ps;
  for(int i=0;i<n;i++){
    int x,y; cin >> x >> y;
    ps.emplace_back(x,y);
    st.insert(pair<int,int>(x,y));
  }
  sort(ps.begin(),ps.end());
  long long ans = 0;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      auto [x1,y1] = ps[i];
      auto [x2,y2] = ps[j];
      if(x1 > x2){
        swap(x1,x2);
        swap(y1,y2);
      }
      if(x1 >= x2) continue;
      if(y1 >= y2) continue; 
      if(st.count(make_pair(x1,y2)) && st.count(make_pair(x2,y1))){
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

