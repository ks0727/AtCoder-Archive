#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  for(int i=0;i<=n/4;i++){
    int now = n;
    now -= i*4;
    if(now%7 == 0){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}

