#include <iostream>
#include <algorithm>
using namespace std;
int p[1001];

int main(){
  int n;
  cin >> n;
  int m;
  cin >> m;
  for(int i=1;i<=n;++i) cin >> p[i];
  int sz = n+1;
  sort(p,p+sz);
  int rest = m;
  for(int i=0;i<4;++i){
    int x = lower_bound(p,p+sz,rest) - p;
    if(x == sz) rest -= p[sz-1];
    else{
      if(rest >= p[x]) rest -= p[x];
      else{
        if(x == 0) continue;
        else rest -= p[x-1];
      }
    }
  }
  cout << m - rest << endl;
  return 0;
}

