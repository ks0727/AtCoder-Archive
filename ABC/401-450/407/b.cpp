#include <iostream>
using namespace std;

int main(){
  int x,y;
  cin >> x >> y;
  int c = 0;
  for(int i=1;i<=6;i++){
    for(int j=1;j<=6;j++){
      if(i+j >= x) c++;
      else if(abs(i-j) >= y) c++;
    }
  }
  double ans = (double)c/36.0;
  printf("%.10f\n",ans);
  return 0;
}

