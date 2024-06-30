#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  string s;
  cin >> s;
  int a[4];
  rep(i,4) a[i] = s[i]-'0';
  int ans = 0;
  rep(i,8){
    int now = a[0];
    rep(j,3){
        if(i & 1 << j){
          now += a[j+1];
        }else{
          now -= a[j+1];
          }
      }
   if (now == 7){
      ans = i;
      break;
     }
  }
  cout << a[0];
  rep(i,3){
    if(ans & 1<<i){
      cout << '+' << a[i+1];    
    }else{
      cout << '-' << a[i+1];
      }
  }
  cout << "=7" << endl;
  return 0;
}

