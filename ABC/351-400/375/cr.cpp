#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<string> b = a;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int nr = min({i+1,n-i,j+1,n-j});
      nr %= 4;
      int ci = i,cj = j;
      for(int k=0;k<nr;k++){
        int ni = cj; int nj = n-ci-1;
        ci = ni; cj = nj;
      }
      b[ci][cj] = a[i][j];
    }
  }
  for(int i=0;i<n;i++) cout << b[i] << endl; 
  return 0;
}

