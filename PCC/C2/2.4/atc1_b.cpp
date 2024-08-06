#include <iostream>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;

int main(){
  int n,q;
  cin >> n >> q;
  dsu uf(n);
  while(q--){
    int p,a,b;
    cin >> p >> a >> b;
    if(p == 0) uf.merge(a,b);
    else{
      if(uf.same(a,b)) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
  return 0;
}

