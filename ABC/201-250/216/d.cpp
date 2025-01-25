#include<iostream>
#include<queue>
#include<vector>
#include<set>
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
  set<int> st;
  vector<int> ps(n,-1);
  queue<pair<int,int> > q;
  for(int i=0;i<m;i++){
    if(a[i].size() == 0) continue;
    q.emplace(a[i].back(),i);
  }
  while(!q.empty()){
    auto [open,pile] = q.front(); q.pop();
    if(ps[open] != -1){
      if(a[ps[open]].size() != 0) {
        q.emplace(a[ps[open]].back(),ps[open]);
        a[ps[open]].pop_back();
      }
      if(a[pile].size() != 0){
         q.emplace(a[pile].back(),pile);
         a[pile].pop_back();
      }
    }else{
       ps[open] = pile;
    }
  }
 for(int i=0;i<m;i++){
   if(a[i].size() != 0){
     cout << "No" << endl;
     return 0;
   }
 }
 cout << "Yes" << endl;
}
