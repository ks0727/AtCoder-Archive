#include <iostream>
using namespace std;


int main(){
  char s[3];
  for(int i=0;i<3;i++) cin >> s[i];
  char t[3];
  for(int i=0;i<3;i++) cin >> t[i];
  int same = 0;
  for(int i=0;i<3;i++) if(s[i] == t[i]) same++;
  if(same == 0) {
    cout << "Yes" << endl;
  }else if(same == 1){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
  return 0;
}

