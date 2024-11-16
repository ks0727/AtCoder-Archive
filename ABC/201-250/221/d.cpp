#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<pair<int,int> > ps;
  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    ps.emplace_back(a,i);
    ps.emplace_back(a+b,i);
  }
  sort(ps.begin(),ps.end());
  vector<int> d(n+1);
  set<int> st;
  int prev = 0;
  for(auto [day,idx] : ps){
    d[st.size()] += day-prev;
    if(st.count(idx)){
      st.erase(idx);
    }else{
      st.insert(idx);
    }
    prev = day;
  }
  for(int i=1;i<=n;i++) cout << d[i] << ' '; cout << endl;
  return 0;
}

