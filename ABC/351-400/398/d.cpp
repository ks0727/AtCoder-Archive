#include <iostream>
#include<set>
using namespace std;

int main(){
  int n,r,c;
  cin >> n >> r >> c;
  string s;
  cin >> s;
  vector<int> ver,hor;
  for(int i=0;i<n;i++){
    if(s[i] == 'N'){
      ver.push_back(-1);
      hor.push_back(0);
    }
    else if(s[i] == 'E'){
      hor.push_back(1);
      ver.push_back(0);
    }
    else if(s[i] == 'W') {
      hor.push_back(-1);
      ver.push_back(0);
    }
    else if(s[i] == 'S'){
      hor.push_back(0);
      ver.push_back(1);
    }
  }
  vector<int> sv(n+1),sh(n+1);  
  for(int i=0;i<n;i++){
    sv[i+1] = sv[i] +ver[i];
    sh[i+1] = sh[i] + hor[i];
  }
  for(int i=1;i<=n;i++){
    if(sv[i] == r && sh[i] == c) cout << 1;
    else cout << 0;
  }
  cout << endl;   
  return 0;
}
