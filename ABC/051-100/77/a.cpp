#include <iostream>
#include<vector>
using namespace std;

int main(){
  int h = 2, w = 3;
  vector<string> c(h);
  for(int i=0;i<h;i++) cin >> c[i];
  for(int k=0;k<2;k++){
    vector<string> old(w,string(h,'/'));
    swap(c,old);
    for(int i=0;i<h;i++)for(int j=0;j<w;j++) c[j][h-i] = old[i][j];
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++)cout << c[i][j];
    cout << endl;
  }
  return 0;
}

