#include <iostream>
using namespace std;
int a[1<<17];
bool know[1<<17];
int main(){
  int n,x;
  cin >> n >> x;
  for(int i=0;i<n;i++) cin >> a[i],a[i]--;
  x--;
  int v = x;
  int ans = 0;
  while(!know[v]){
    know[v] = true;
    ans++;
    v = a[v];
  }
  cout << ans << endl;
}
  
