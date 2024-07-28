#include <iostream>
using namespace std;
int a[100];
bool exist[4];
int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;++i) cin >> a[i];
  int ans = 0;
  for(int i=0;i<n;++i){
    exist[0] = true;
    for(int j=3;j>=0;j--){
      if(exist[j]){
        int nj = j + a[i];
        if(nj >= 4){
          exist[j] = false;
          ans++;
        }else{
          exist[j] =false;
          exist[nj] = true;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

