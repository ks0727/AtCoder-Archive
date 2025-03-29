#include <iostream>
using namespace std;

int main(){
  string s;
  cin >> s;
  bool need_i = true;
  int ans = 0;
  for(int i=0;i<s.size();i++){
    if(need_i && s[i] != 'i'){
      ans++;
      need_i = false;
    }else if(!need_i && s[i] != 'o'){
      ans++;
      need_i = true;
    }else{
      need_i ^= 1;
    }
  }
  if((s.size()+ans)%2 == 1) ans++;
  cout << ans << endl;
  return 0;
}

