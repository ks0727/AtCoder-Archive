#include <iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  vector<bool> isB(n);
  int now = 0;
  while(q--){
    int a; cin >> a; a--;
    if(isB[a]){ 
      isB[a] = false;
      if(n==1) now--;
      else if(a != 0 && a != n-1){
        if(!isB[a-1] && !isB[a+1]) now--;
        if(isB[a-1] && !isB[a+1]) now += 0;
        if(!isB[a-1] && isB[a+1]) now += 0;
        if(isB[a-1] && isB[a+1]) now++;
      } else if(a == 0){
        if(!isB[a+1]) now--;
      }else if(a == n-1){
        if(!isB[a-1]) now--;
      }
    }else{
      isB[a] = true;
      if(n==1) now++;
      else{
      if(a != 0 && a != n-1){
        if(!isB[a-1] && !isB[a+1]) now++;
        if(isB[a-1] && !isB[a+1]) now += 0;
        if(!isB[a-1] && isB[a+1]) now += 0;
        if(isB[a-1] && isB[a+1]) now--;
      }else if(a == 0){
        if(!isB[a+1]) now++;
      }else if(a == n-1){
        if(!isB[a-1]) now++;
      }
    }
  }
  cout << now << endl;
}
}


