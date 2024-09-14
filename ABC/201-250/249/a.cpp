#include <iostream>
using namespace std;

int main(){
  int a,b,c,d,e,f,x;
  cin >> a >> b >> c >> d >> e >> f >>x;
  
  int ao=0,ta = 0;
  int y = x/(a+c);
  int s = x%(a+c);
  ta += y*b*a;
  if(s >= a) ta += a*b;
  else ta += s*b; 

  int z = x/(d+f);
  int t = x%(d+f);
  ao += z*e*d;
  if(t >= d) ao += d*e;
  else ao += t*e;
  
  if(ao > ta) cout << "Aoki" << endl;
  else if(ao < ta) cout << "Takahashi" << endl;
  else cout << "Draw" << endl;
  return 0;
}

