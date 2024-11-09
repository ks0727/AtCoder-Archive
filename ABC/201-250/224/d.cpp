#include <iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;

int main(){
  int m;
  cin >> m;
  vector<vector<int> > g(9);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> p(9,-1);
  for(int i=0;i<8;i++){
    int x;
    cin >> x;
    x--;
    p[x] = i;
  }
  map<vector<int>, int> mp;
  queue<vector<int> > q; 
  q.emplace(p);
  mp[p] = 0;
  while(!q.empty()){
    vector<int> a = q.front(); q.pop();
    int emp = -1;
    for(int i=0;i<9;i++) if(a[i] == -1) emp = i;
    for(int u : g[emp]){
      auto b = a;
      swap(b[emp],b[u]);
      if(mp.count(b)) continue;
      q.push(b);
      mp[b] = mp[a]+1;
    }
  }
  vector<int> ans;
  for(int i=0;i<8;i++) ans.push_back(i);
  ans.push_back(-1);
  if(mp.count(ans)) cout << mp[ans] << endl;
  else cout << -1 << endl;
  return 0;
}

