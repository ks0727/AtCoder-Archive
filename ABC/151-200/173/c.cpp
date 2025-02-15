#include <iostream>
#include<vector>
using namespace std;

int main(){
  int h,w,k;
  cin >>h >> w >> k;
  vector<string> s(h);
  int ans = 0;
  for(int i=0;i<h;i++) cin >> s[i];
  for(int i=0;i<1<<h;i++){
    for(int j=0;j<1<<w;j++){
      vector<string> t = s;
      for(int k=0;k<h;k++){
        if(i>>k&1) t[k] = string('&',w);
      }
      for(int k=0;k<w;k++){
        for(int l=0;l<h;l++){
          if(j>>k&1) t[l][k] = '&';
        }
      }
      int now = 0;
      for(int k=0;k<h;k++)for(int l=0;l<w;l++) if(t[k][l] == '#') now++;
      if(now == k) ans++;
    }
  }
  cout << ans << endl;  
  return 0;
}

