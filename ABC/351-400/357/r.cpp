#include <iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n),dim(n);
  for(int i=0;i<n;i++) cin >> a[i],a[i]--;
  for(int i=0;i<n;i++) dim[a[i]]++;
  queue<int> q;
  for(int i=0;i<n;i++) if(dim[i] == 0) q.push(i);
  while(!q.empty()){
    int v = q.front(); q.pop();
    int u = a[v];
    dim[u]--;
    if(dim[u] == 0) q.push(u);
  }
  vector<int> ans(n);
  for(int i=0;i<n;i++){
    if(ans[i] == 0 && dim[i] != 0){
      int v = i;
      int c = 0;
      do{
        c++;
        v = a[v];
      }while(v != i);
      do{
        ans[v] = c;
        v = a[v];
      }while(v != i);
    }
  }
  for(int i=0;i<n;i++){
    if(ans[i] != 0) continue;
    auto dfs = [&](auto dfs, int v)->int{
      if(ans[v] != 0) return ans[v];
      int res = dfs(dfs,a[v])+1;
      return ans[v] = res;
    };
    dfs(dfs,i);
  }
  long long t = 0;
  for(int i=0;i<n;i++) t += ans[i];
  cout << t << endl;
}

