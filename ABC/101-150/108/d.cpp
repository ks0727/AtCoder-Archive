#include <iostream>
#include<vector>
using namespace std;

int main(){
  int l;
  cin >> l;
  int cnt = 0;
  int d = l;
  while(d){
    cnt++;
    d >>= 1;
  }
  
  return 0;
}

