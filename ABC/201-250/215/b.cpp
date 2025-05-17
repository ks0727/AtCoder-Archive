#include <iostream>
using namespace std;

int main(){
  long long n;
  cin >> n;
  long long now = 1;
  for(int i=0;i<60;i++){
    now *= 2;
    if(now > n){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}

