#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  vector<int> a(n);
  for(int i=0;i<n;i++) a[i] = i+1;
  int offset = 0;
  while(q--){
    int type;
    cin >> type;
    if(type == 1){
      int p,x;
      cin >> p >> x;
      p--;
      a[(p+offset)%n] = x;
    }else if(type == 2){
      int p; cin >> p; p--;
      cout << a[(p+offset)%n] << endl;
    }else if(type == 3){
      int k; cin >> k; offset += k;
      offset %= n;
    }
  }
  return 0;
}

