#include <iostream>
#include <vector>
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  vector a(h,vector<int>(w));
  vector b(w,vector<int>(h));
  for(int i=0;i<h;i++)for(int j=0;j<w;j++) cin >> a[i][j];
  for(int i=0;i<w;i++)for(int j=0;j<h;j++) b[i][j] = a[j][i];
  for(int i=0;i<w;i++)
  {
    for(int j=0;j<h;j++) cout << b[i][j] << ' ';
    cout << endl;

  }
  return 0;
}

