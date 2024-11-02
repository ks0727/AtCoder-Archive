#include <iostream>
#include <vector>
using namespace std;

long long modpow(int x, long long k,int mod){
  if(k == 0) return 1;
  long long y = modpow(x,k/2,mod);
  long long res =(y*y)%mod;
  if(k %2 == 1){
    res *= x;
    res %= mod;
  }
  return res;
}
int main(){
  int n; long long k;
  cin >> n >> k;
  vector<int> p(n);
  for(int i=0;i<n;i++) cin >> p[i],p[i]--;
  vector<bool> visited(n);
  vector<int> ans(n);
  for(int i=0;i<n;i++){
    if(!visited[i]){
      int v = i;
      vector<int> seen;
      do{
        seen.push_back(v);
        v = p[v];
      }while(v != i);
      int c = seen.size();
      long long move = modpow(2,k,c);
      for(int j=0;j<c;j++){
        visited[seen[j]] = true;
        ans[seen[j]] = seen[(j+move)%c];
      }
    }
  }
  for(int i=0;i<n;i++) cout << ans[i]+1 << ' '; cout << endl;
  return 0;
}

