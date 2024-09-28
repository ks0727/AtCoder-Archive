#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin >> s[i];
  auto f = [&](string t){
    if(t.size()<6) return false;
    int cnt = 0;
    for(int i=0;i<6;i++) if(t[i] == '#') cnt++;
    if(cnt >= 4) return true;
    for(int i=1;i<t.size()-5;i++){
      if(t[i-1] == '#') cnt--;
      if(t[i+5]== '#') cnt++;
      if(cnt >= 4) return true;
    }
    return false;
  };
  {
    for(int i=0;i<n;i++) if(f(s[i])){
      cout << "Yes" << endl;
      return 0;
    }
  }
  {
    for(int i=0;i<n;i++){
      string t = "";
      for(int j=0;j<n;j++){
        t += s[j][i];
      }
      if(f(t)){
        cout << "Yes" << endl;
        return 0;
      }
    }
  } 
  {
    for(int i=0;i<n;i++){
      int j = 0;
      int ni = i;
      int nj = j;
      string t ="";
      while(true){
        if(ni >=n || nj >= n) break;
        t += s[ni][nj];
        ni++; nj++;
      }
      if(f(t)){
        cout << "Yes" << endl;
        return 0;
      }
    }
    for(int j=0;j<n;j++){
      int i = 0;
      int ni = i;
      int nj = j;
      string t = "";
      while(true){
        if(ni >= n || nj >= n) break;
        t += s[ni][nj];
        ni++;
        nj++;
      }
      if(f(t)){
        cout << "Yes"<< endl;
        return 0;
      }
    }
  }
  {
    for(int i=0;i<n;i++){
      int j = n-1;
      int ni = i;
      int nj = j;
      string t = "";
      while(true){
        if(ni>=n||nj<0) break;
        t+= s[ni][nj];
        ni++; nj--;
      }
      if(f(t)){
        cout << "Yes" << endl;
        return 0;
      }
    }
    for(int j=0;j<n;j++){
      int i=0;
      int ni = i;
      int nj = j;
      string t = "";
      while(true){
        if(ni>=n||nj<0) break;
        t+=s[ni][nj];
        ni++; nj--;
      }
      if(f(t)){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}

