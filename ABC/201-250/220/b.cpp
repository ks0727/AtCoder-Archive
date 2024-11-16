#include <iostream>
using namespace std;

int tode(string x,int k){
  int res = 0;
  for(int i=0;i<x.size();i++){
    res = res*k + x[i]-'0';
  }
  return res;
}

int main(){
  int k;
  string a,b;
  cin >> k >> a >> b;
  int ax = tode(a,k);
  int bx = tode(b,k);
  long long ans = (long long)ax*bx;
  cout << ans << endl; 
  return 0;
}

