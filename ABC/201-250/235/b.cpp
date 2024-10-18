#include <iostream>
using namespace std;
int h[1<<17];
int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++) cin >> h[i];
  int ans = 0;
  for(int i=0;i<n-1;i++){
    if(h[i] >= h[i+1])
    {
      cout << h[i] << endl;
      return 0;
    }
  }
  cout << h[n-1] << endl;
  return 0;
}

