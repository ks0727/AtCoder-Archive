#include <iostream>
#include <vector>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  a--; b--;
  int ai = a/3,aj = a%3;
  int bi = b/3,bj = b%3;
  if(ai == bi && aj == bj-1){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}

