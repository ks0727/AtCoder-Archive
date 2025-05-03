#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  long long ans = 1e18;
  for(int i=0;i<1<<(n-1);i++){
    vector<int>now;
    for(int j=0;j<n-1;j++){
      if(i>>j&1) now.push_back(j);
    }
    now.push_back(n-1);
    long long cur = 0;
    int k=0;
    for(int j=0;j<now.size();j++){
      int nxt = now[j];
      vector<int> b;
      while(k<=nxt){
        b.push_back(a[k]);
        k++; 
      }
      long long r = 0;
      for(int l=0;l<30;l++){
        for(int m=0;m<b.size();m++){
          if(b[m]>>l&1){
            r += 1LL<<l;
            break;
          }
        }
      }
      cur ^= r;
    }
    ans = min(ans,cur);
  }
  cout << ans << endl; 
  return 0;
}

