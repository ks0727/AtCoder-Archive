#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int> > a(m);
  vector<vector<int> > pos(n);
  for(int i=0;i<m;i++){
    int k;
    cin >> k:
    a[i] = vector<int>(k);
    for(int j=0;j<k;j++) cin >> a[i][j];
    for(int j=0;j<k;j++){
      a[i][j]--;
      pos[a[i][j]].push_back(i);
  }
  vector<int> cnt(n);
  queue<int> q;
  for(int i=0;i<m;i++){
    int t = a[i].back();
    cnt[t]++;
  }
  for(int i=0;i<n;i++)if(cnt[i] == 2) q.push(i);
  int take = 0;
  while(!q.empty()){
    int x = q.front(); q.pop();
    take++;
    for(int i=0;i<2;i++){
      int p = pos[x][i];
      a[p].pop_back();
      if(a[p].size() != 0) {
        int t = a[p].back();
        cnt[t]++;
        if(cnt[t] == 2) q.push(t);
      }
    }
  }
  if(take == n) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

