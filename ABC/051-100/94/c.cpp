#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> x(n);
  for(int i=0;i<n;i++) cin >> x[i];
  vector<int> y = x;
  sort(y.begin(),y.end());
  int a = y[n/2-1];
  int b = y[n/2];
  for(int i=0;i<n;i++){
    if(x[i] <= a) cout << b << endl;
    else cout << a << endl;
  }
  return 0;
}

