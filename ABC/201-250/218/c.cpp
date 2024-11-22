#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> s(n),t(n);
  for(int i=0;i<n;i++) cin >> s[i];
  for(int i=0;i<n;i++) cin >> t[i];
  if(s==t){
    cout << "Yes" << endl;
    return 0;
  }
  int cs = 0,ct=0;
  for(int i=0;i<n;i++)for(int j=0;j<n;j++) if(s[i][j] == '#') cs++;
  for(int i=0;i<n;i++)for(int j=0;j<n;j++) if(t[i][j] == '#') ct++;
  if(cs != ct){
    cout << "No" << endl;
    return 0;
  }
  int ub=300,lb=300,bb=-1,rb=-1;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(t[i][j] == '#'){
        lb = min(lb,j);
        rb = max(rb,j);
        ub = min(ub,i);
        bb = max(bb,i);
      }
    }
  }
  for(int di=-ub;di<=n-bb-1;di++){
    for(int dj=-lb;dj<=n-rb-1;dj++){
      vector<string> nt(n,string(n,'.'));
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          int pi = i-di;
          int pj = j-dj;
          if(pi < 0 || pj < 0 || pi >= n || pj >= n) continue;
          nt[i][j] = t[pi][pj];
        }
      }
      vector<string> old = nt;
      for(int r=0;r<4;r++){
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            nt[j][n-i-1] = old[i][j];
          }
        }
        if(nt == s){
          cout << "Yes" << endl;
          return 0;
        }else{
          swap(nt,old);
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}

