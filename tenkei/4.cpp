#include <iostream>
#include<vector>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<int> > a(h,vector<int>(w));
  for(int i=0;i<h;i++)for(int j=0;j<w;j++) cin >> a[i][j];  
  vector<long long> sh(w),sv(h);
  for(int i=0;i<h;i++)for(int j=0;j<w;j++) sv[i]+= a[i][j];
  for(int i=0;i<h;i++)for(int j=0;j<w;j++) sh[j]+= a[i][j];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cout << sv[i]+sh[j]-a[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}

