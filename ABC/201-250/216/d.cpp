#include <iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int> > a(m);
  for(int i=0;i<m;i++){
    int k;
    cin >> k;
    for(int j=0;j<k;j++){
      int x;
      cin >> x;
      x--;
      a[i].push_back(x);
    }
  }
  const int INF = 1e9;
  vector<int> pos(n,-1);
  queue<pair<int,int> > q;
  for(int i=0;i<m;i++){
    if(pos[a[i].back()] != -1){
      pos[a[i].back()] = INF;
      a[i].pop_back();
      if(a[i].size() != 0) q.emplace(a[i].back(),i);
    }else{
      pos[a[i].back()] = i;
    }
  }
  while(!q.empty()){
    auto [val,idx] = q.front(); q.pop();
    if(pos[val] != -1){
      a[idx].pop_back();
      if(a[idx].size() != 0) q.emplace(a[idx].back(),idx);
    }else{
      pos[val] = idx;
    }
  }
  for(int i=0;i<m;i++){
    if(a[i].size() != 0){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}

