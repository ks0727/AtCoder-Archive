#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> a(n+1);
  vector<int> c(n+m+1);
  for(int i=0;i<n+1;i++) cin >> a[i];
  for(int i=0;i<n+m+1;i++) cin >> c[i];
  vector<int> b(m+1);
  for(int i=m;i>=0;i--){
    b[i] = c[i+n]/a[n];
    for(int j=n-1;j>=0;j--){
      c[i+j] -= a[j]*b[i];
    }
  }
  for(int i=0;i<m+1;i++) cout << b[i] << ' '; cout << endl;
  return 0;
}

