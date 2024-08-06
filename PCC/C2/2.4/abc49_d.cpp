#include <iostream>
#include <vector>
#include <set>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
int ans[2<<17];

int main(){
  int n,k,l;
  cin >> n >> k >> l;
  dsu uf1(n),uf2(n);
  for(int ki=0;ki<k;ki++){
    int p,q;
    cin >> p >> q;
    p--; q--;
    if(!uf1.same(p,q)){
       uf1.merge(p,q);
     }
   }
  for(int li=0;li<l;li++){
    int r,s;
    cin >> r >> s;
    r--; s--;
    if(!uf2.same(r,s)){
     uf2.merge(r,s);
    }
  }
  for(int i=0;i<n;i++)
  return 0;
}

