#include <iostream>
using namespace std;
using ll = long long;
int a[2<<17];
int cnt[1<<20];
ll s[1<<20];

int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cnt[a[i]]++;
  const int M = 1e6;
  ll ans = 0;
  for(ll i=0;i<M+5;i++) s[i+1] = s[i] + cnt[i];
  for(ll i=1;i<M+5;i++){
    int j=i;
    while(j >0){
      int x = i/j;
      int nx = x+1;
      int nj = i/nx;
      j = nj;
    }
  }
  cout << ans << endl;
}


