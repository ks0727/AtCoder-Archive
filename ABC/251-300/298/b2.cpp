#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int n;
  cin >> n;
  vector<string> a(n),b(n);
  rep(i,n){
    rep(j,n){
      char c;
      cin >> c;
      a[i]+=c;
    }
  }
  rep(i,n){
    rep(j,n){
      char c;
      cin >> c;
      b[i]+=c;
    }
  }
  auto rotate = [&](vector<string> &s)->vector<string>{
     vector<string> ns = s;
     rep(i,n)rep(j,n){
       ns[i][j] = s[n-j-1][i];
     }
     return ns;
  };
  auto same = [&](vector<string> &s, vector<string> &t)->bool{
      rep(i,n){
        rep(j,n){
          if(s[i][j] == '1' && t[i][j] == '0')return false;
        }
      }
      return true;
  };
  
  rep(i,4){
    if(same(a,b)){
      cout << "Yes" << endl;
      return 0;
    }else{
      a = rotate(a);
    }
  }
  cout << "No" << endl;
  return 0;
}
