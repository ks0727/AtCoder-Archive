#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  vector<bool> isp(200,true);
  isp[0] = isp[1] = false;
  for(int i=0;i<200;i++)
  {
    if(!isp[i]) continue;
    for(int j=i*2;j<200;j+=i) isp[j] = false;
  }
  for(int i=a;i<=b;i++)
  {
    bool ok = true;
    for(int j=i+c;j<=i+d;j++)
    {
      if(isp[j])
      {
        ok = false;
        break;
      }
    }
    if(ok)
    {
      cout << "Takahashi" << endl;
      return 0;
    }
  }
  cout << "Aoki" << endl;
  return 0;
}

