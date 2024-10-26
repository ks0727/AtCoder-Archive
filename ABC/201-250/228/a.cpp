#include <iostream>
using namespace std;

int main(){
  int s,t,x;
  cin >> s >> t >> x;
  while(s != t){
    if(s == x){
      cout << "Yes" << endl;
      return 0;
    }
    s++;
    if(s == 24) s = 0;
  }
  cout << "No" << endl;
  return 0;
}

