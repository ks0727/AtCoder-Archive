#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  string a,b;
  cin >> a >> b;
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  int n = min(a.size(),b.size());
  for(int i=0;i<n;i++){
    int ai = a[i]-'0';
    int bi = b[i]-'0';
    if(ai+bi>=10){
      cout << "Hard" << endl;
      return 0;
    }
  }
  cout << "Easy" << endl; 
  return 0;
}

