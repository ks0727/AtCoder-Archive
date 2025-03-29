#include <iostream>
#include<set>
using namespace std;

int main(){
  int n,R,C;
  cin >> n >> R >> C;
  string s;
  cin >> s;
  int r=0,c=0; //いまの焚き火の位置を動かす
  using P = pair<int,int>;
  set<P> smokes;
  smokes.emplace(0,0);
  string ans;
  for(int i=0;i<n;i++){
    if(s[i] == 'N') r++;
    else if(s[i] == 'S') r--; 
    else if(s[i] == 'W') c++; 
    else if(s[i] == 'E') c--; 
    smokes.emplace(r,c);
    int tr = r+R; int tc = c+C;
    if(smokes.count(P(tr,tc)) ans += '1';
    else ans += '0';
  }
  return 0;
}

