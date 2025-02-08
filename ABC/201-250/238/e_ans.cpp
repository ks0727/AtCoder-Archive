#include <iostream>
#include<vector>
#include<atcoder/dsu>
using namespace std;
using namespace atcoder;
int main(){
  int n,q;
  cin >> n >> q;
  dsu d(n+1);
  while(q--){
    int l,r;
    cin >> l >> r;
    l--;
    d.merge(l,r);
  }
  if(d.same(0.n)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

