#include <iostream>
using namespace std;

int main(){
  for(int i=0;i<26;i++){
    int p;
    cin >> p;
    p--;
    char ans = 'a'+p;
    cout << ans;
  }
  cout << endl;
  return 0;
}

