#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  int di[]  = {0,1,0,-1};
  int dj[]  = {1,0,-1,0};
  vector<string> b = a;
  int si = 0,sj = 0;
  for(int d=0;d<4;d++){
    while(true){
      int ni = si;
      int nj = sj;
      ni += di[d];
      nj += dj[d];
      if(ni == -1 || nj == -1 || ni == n || nj == n) break;
      b[ni][nj] = a[si][sj];
      si = ni; sj = nj;
    }
  }
  for(int i=0;i<n;i++) cout << b[i] << endl;
    
  return 0;
}

