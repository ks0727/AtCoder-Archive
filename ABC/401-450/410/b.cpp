#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  vector<int> cnt(n);
  for(int i=0;i<q;i++){
    int x; cin >> x; x--;
    if(x == -1){
      int now = 1001001001;
      for(int j=0;j<n;j++) now = min(now,cnt[j]);
      for(int j=0;j<n;j++){
        if(cnt[j] == now){
          cnt[j]++;
          cout << j+1 << ' ';
          break;
        }
      }
    }else{
      cnt[x]++;
      cout << x+1 << ' ';
    }
  }
  cout << endl;   
  return 0;
}

