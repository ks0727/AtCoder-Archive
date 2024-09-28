#include <iostream>
using namespace std;
int a[2<<17];
int visited[2<<17];
int main(){
  int n; long long k;
  cin >> n >> k;
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) visited[i] = -1;
  int v = 0;
  int cnt = 0;
  long long ans = 0;
  while(visited[v] == -1){
    visited[v] = cnt;
    cnt++;
    ans += a[v];
    v += a[v];
    v %= n;
    k--;
    if(k==0) break;
  }
  if(k==0){
    cout << ans << endl;
    return 0;
  }
  long long m = cnt - visited[v];
  int u = v;
  long long cycle = 0;
  do{
    cycle += a[u];
    u += a[u];
    u %= n;
  }while(u != v);
  ans += (k/m)*cycle;
  k %= m;
  for(int i=0;i<k;i++){
    ans += a[v];
    v += a[v];
    v %= n;
  }
  cout << ans << endl;
} 
  
    
