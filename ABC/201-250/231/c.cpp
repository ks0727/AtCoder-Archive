#include <iostream>
#include <algorithm>
using namespace std;
int a[2<<17];
int main(){
  int n,q;
  cin >> n >> q;
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a,a+n);
  while(q--){
    int x;
    cin >> x;
    int id = lower_bound(a,a+n,x) - a;
    cout << n-id << endl;
  }
  return 0;
}

