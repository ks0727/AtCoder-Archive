#include <iostream>
using namespace std;
int di[] = {1,-1,1,-1,2,-2,2,-2};
int dj[] = {2,2,-2,-2,1,1,-1,-1};
int main(){
  long long x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    {
      int nx1 = x1+dj[i];
      int ny1 = y1+di[i];
      int nx2 = x2+dj[j];
      int ny2 = y2+di[j];
      if(nx1 == nx2 && ny1 == ny2)
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}

