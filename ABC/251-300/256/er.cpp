#include <iostream>
#include <queue>
using namespace std;
int x[2<<17];
int dim[2<<17];
long long c[2<<17];
bool finished[2<<17];
int main()
{
  int n;
  cin >>n ;
  for(int i=0;i<n;i++) cin >> x[i],x[i]--;
  for(int i=0;i<n;i++) cin >> c[i];
  for(int i=0;i<n;i++) dim[x[i]]++;
  long long ans = 0;
  queue<int> q;
  for(int i=0;i<n;i++) if(dim[i]==0) q.push(i);
  while(!q.empty()){
    int v = q.front(); q.pop();
    int u = x[v];
    dim[u]--;
    if(dim[u]==0) q.push(u);
  }
  for(int i=0;i<n;i++){
    if(dim[i] != 0 && !finished[i]){
      long long now = 1e18;
      int v = i;
      do{
        finished[v] = true;
        now = min(now,c[v]);
        v = x[v];
      }while(v != i);
      ans += now;    
     }
  }
  cout << ans << endl;
  return 0;
}
  
