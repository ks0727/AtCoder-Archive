#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using T = tuple<int,int,int>;
int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<int,int> > choco(n),box(m);
  vector<T> event;
  multiset<int> st;
  for(int i=0;i<n;i++) cin >> choco[i].first;
  for(int i=0;i<n;i++) cin >> choco[i].second;
  for(int i=0;i<m;i++) cin >> box[i].first;
  for(int i=0;i<m;i++) cin >> box[i].second;
  for(int i=0;i<n;i++) event.emplace_back(choco[i].first,-choco[i].second,1);
  for(int i=0;i<m;i++) event.emplace_back(box[i].first,-box[i].second,0);
  //for(int i=0;i<n;i++) choco[i].second *= -1;
  //for(int i=0;i<m;i++) box[i].second *= -1;
  sort(event.begin(),event.end());
  for(int i=0;i<n+m;i++){
    auto [h,w,c] = event[i];
    if(c == 0) st.insert(-w);
    else{
      auto it = st.lower_bound(-w);
      if(it == st.end()){
        cout << "No" << endl;
        return 0;
      }else{
        st.erase(it);
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}

