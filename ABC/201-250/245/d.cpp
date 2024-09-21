#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n,m;
  cin >> n>> m;
  vector<int> a(n+1),c(n+m+1),b(m+1);
  for(int i=0;i<n+1;i++) cin >> a[i];
  for(int i=0;i<n+m+1;i++) cin >> c[i];
  for(int i=m;i>=0;i--){
    int now = c[i+n];
    for(int j=m;j>=i;j--){
      now -= a[n-(m-i)+m-j]*b[j];
    }
    b[i] = now/a[n];
  }
  for(int i=0;i<m+1;i++) cout << b[i] << ' '; cout << endl; 
  return 0;
}

