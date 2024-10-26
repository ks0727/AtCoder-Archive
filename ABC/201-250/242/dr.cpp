#include <iostream>
using namespace std;

int main(){
  string s;
  cin >> s;
  int q;
  cin >> q;
  string abc = "ABC";
  while(q--){
    long long t,k;
    cin >> t >> k;
    k--;
    if(t == 0){
      cout << s[k] << '\n';
      continue;
    }
    int init = -1;
    if(t > 61) init = 0;
    else{
      for(int i=0;i<t;i++){
        k /= 2;
      }
      init = k;
    }
    int add = 0;
    for(int i=0;i<61;i++){

    cout << abc[id] << '\n';
  }
  return 0;
}

