#include <iostream>
using namespace std;
int h[3],w[3];

int main(){
  for(int i=0;i<3;i++) cin >> h[i];  
  for(int i=0;i<3;i++) cin >> w[i];  
  int ans = 0;
  for(int a=1;a<=30;a++){
    for(int b=1;b<=30;b++){
      for(int c=1;c<=30;c++){
        for(int d=1;d<=30;d++){
          if(a+b >= h[0] || c + d >= h[1] || a+c>=w[0] || b+d >= w[1])  continue;
          int e = h[0] - a - b;
          int f = h[1] - c - d;
          int g = w[0] - a - c;
          int k = w[1] - b - d;
          if(e+f >= w[2] || g + k >= h[2]) continue;
          int x = w[2] - e - f;
          int y = h[2] - g - k;
          if(x != y) continue;
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

