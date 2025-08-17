#include <iostream>
using namespace std;

int main(){
  int n,s;
  cin >> n >> s;
  int prev = 0;
  for(int i=0;i<n;i++){
    int t;
    cin >> t;
    if(t-prev > s){
      cout << "No" << endl;
      return 0;
    }
    prev = t;
  }
  cout << "Yes" << endl;
  return 0;
}

