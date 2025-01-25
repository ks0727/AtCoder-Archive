#include <iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main(){
  int v1,v2,v3;
  cin >> v1 >> v2 >> v3;
  for(int a=0;a<=14;a++){
    for(int b=0;b<=14;b++){
      for(int c=0;c<=14;c++){
        for(int d=0;d<=14;d++){
          for(int e=0;e<=14;e++){
            for(int f=0;f<=14;f++){
              int u3 = (7-max(a,d))*(7-max(b,e))*(7-max(c,f));
              if(u3 != v3) continue;
              //cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << endl;
              int u2 = (7-a)*(7-b)*(7-c)+(7-d)*(7-e)*(7-f);
              u2 += (min(a+7,d+7)- max(a,d))*(min(b+7,e+7)-max(b,e))*(min(c+7,f+7)-max(c,f));
              u2 -= 3*u3;
              if(u2 != v2) continue;
              int u1 = 7*7*7*3 - 2*u2 - 3*u3;
              if(u1 != v1) continue;
              cout << "Yes" << endl;
              printf("%d %d %d %d %d %d %d %d %d\n",0,0,0,a,b,c,d,e,f);
              return 0;
            }
          }
        }
      }
    }
  }
  cout << "No" << endl;
}
