#include <iostream>
using namespace std;
const int di[] = {0,-1,0,1};
const int dj[] = {1,0,-1,0};
int main(){
  int n;
  cin >> n;
  string t;
  cin >> t;
  int ci = 0,cj = 0,d = 0;
  for(int i=0;i<n;i++){
    if(t[i] == 'S'){
      ci += di[d]; cj += dj[d];
    }else{
      d++;
      d%=4;
    }
  }
  cout << cj << ' ' << ci << endl;
  return 0;
}

