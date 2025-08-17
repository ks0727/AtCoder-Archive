#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> d(n-1);
  for(int i=0;i<n-1;i++) cin >> d[i];
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      int now = 0;
      for(int k=i;k<j;k++) now += d[k];
      cout << now << ' ';
    }
    cout << endl;
  }
  return 0;
}

