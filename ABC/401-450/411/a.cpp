#include <iostream>
using namespace std;

int main(){
  string p;
  cin >> p;
  int l;
  cin >> l;
  if(p.size() >= l) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

