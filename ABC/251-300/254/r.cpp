#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n-k;i++)
  {
    if(a[i] > a[i+k]) swap(a[i],a[i+k]);
  }
  for(int i=0;i<n-1;i++)
  {
    if(a[i] > a[i+1]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
  
