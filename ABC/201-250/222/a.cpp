#include <iostream>
#include<algorithm>
using namespace std;

int main(){
  string n;
  cin >> n;
  reverse(n.begin(),n.end());
  while(n.size() != 4) n += '0';
  reverse(n.begin(),n.end());
  cout << n << endl;
  return 0;
}

