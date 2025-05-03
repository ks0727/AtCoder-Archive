#include <iostream>
using namespace std;

int main(){
  long long n; int m;
  cin >> n >> m;
  long long s = 0;
  long long now = 1;
  m++;
  for(int i=0;i<m;i++){
    s += now;
    if(s > 1000000000){
      cout << "inf" << endl;
      return 0;
    }
    now *= n;
  }
  cout << s << endl;
  return 0;
}

