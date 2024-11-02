#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> dim(n);
  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    dim[a]++;
    dim[b]++;
  }
  for(int i=0;i<n;i++){
    if(dim[i] != 1 && dim[i] != n-1){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl; 
  return 0;
}

