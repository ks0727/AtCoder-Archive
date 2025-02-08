#include <iostream>
using namespace std;

int main(){
  char a,b;
  cin >> a >> b;
  int ai = a-'0';
  int bi = b-'0';
  string sa = "", sb = "";
  for(int i=0;i<bi;i++) sa += a;
  for(int i=0;i<ai;i++) sb += b;
  if(sa < sb) cout << sa << endl;
  else cout << sb << endl;
  return 0;
}

