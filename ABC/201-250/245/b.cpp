#include <iostream>
using namespace std;
bool ok[2001];

int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    ok[x] = true;
  }
  for(int i=0;i<=2000;i++){
    if(!ok[i]){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}

