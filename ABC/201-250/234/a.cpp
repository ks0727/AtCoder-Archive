#include <iostream>
using namespace std;
int f(int x){
  return x*x+2*x+3;
}
int g(int x){
  return f(f(f(x)+x)+f(f(x)));
}

int main(){
  int t;
  cin >> t;
  cout << g(t) << endl; 
  return 0;
}

