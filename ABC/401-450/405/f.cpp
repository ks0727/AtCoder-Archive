#include <iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<tuple>
#include<map>
#include<set>
using namespace std;
using T = tuple<int,int,int>;
int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<int,int> > es;
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    es.emplace_back(a,b);
  }
  int q;
  cin >> q;
  vector<T> os;
  map<pair<int,int>, int> mp;
  for(int i=0;i<q;i++){
    int c,d;
    cin >> c >> d;
    os.emplace_back(c,d);
    mp[make_pair(c,d)] = i;
  }
  sort(es.begin(),es.end());
  sort(os.begin(),os.end());
  vector<T> events;
  for(int i=0;i<n;i++){
    events.emplace_back(os[i].first,0,1);
    events.emplace_back(os[i].second,1,1);
    events.emplace_back(es[i].first,0,0);
    events.emplace_back(es[i].second,1,0);
  }
  vector<int> ans(q);
  set<int> st;
  int cnt = 0;
  for(int i=0;i<events.size();i++){
    auto [val,fors,nt] = events[i]; 
    if(st.count(
  return 0;
}

