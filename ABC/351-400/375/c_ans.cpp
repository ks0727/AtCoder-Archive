#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<string> b = a;
  for(int i=0;i<n;i++)for(int j=0;j<n;j++){
    int ni = i; int nj = k;
    int k = min({ni+1,nj+1,n-ni,n-nj});
    for(int ki=0;ki<k%4;ki++){
      swap(ni,nj);
      nj = n - 1 - nj;
    }
    b[ni][nj] = a[i][j];
  }
  for(int i=0;i<n;i++) cout << b[i] << '\n';
  return 0;
}

