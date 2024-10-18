#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector changed(n,vector<bool>(n));
  vector<string> ans = a;
  for(int k=0;k<n/2;k++){
    for(int i=0;i<n;i++){
      if(i < k || n-k-1 < i) continue;
      for(int j=0;j<n;j++){
        if(j < k || n-k-1 < j) continue;
        if(i+j < n-1 && changed[i][j]){ 
          if(
          a[j][n-i-1] = a[i][j]=='#'?:'.':'#';   
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(!changed[i][j]) cout << a[i][j];
      else{
        if(a[i][j] == '#') cout << '.';
        else cout << '#'; 
      }
    }
    cout << endl;
  }
  return 0;
}

