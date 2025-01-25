#include <iostream>
#include<vector>
using namespace std;

int main(){
  vector<string> s(9);
  for(int i=0;i<9;i++) cin >> s[i];
  int ans = 0;
  for(int i1=0;i1<9;i1++){
    for(int j1=0;j1<9;j1++){
      if(s[i1][j1] != '#') continue;
      for(int i2=0;i2<9;i2++){
        for(int j2=j1;j2<9;j2++){
          for(int i3=i2;i3<9;i3++){
            for(int j3=j1;
    }
  }
  cout << ans << endl;
}

