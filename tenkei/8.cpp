#include <iostream>
#include<vector>
#include<algorithm>
#include<atcoder/modint>
#include<atcoder/fenwicktree>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  fenwick_tree<mint> bit(n+1);
  bit.add(0,1);
  string target = "atcoder";
  for(int k=0;k<7;k++){
    fenwick_tree<mint> old(n+1);
    swap(old,bit);
    for(int i=0;i<n;i++){
      if(s[i] == target[k]){
        mint sum = old.sum(0,i+1);
        bit.add(i+1,sum);
      }
    }
  }
  mint ans = bit.sum(0,n+1);
  cout << ans.val() << endl;
  return 0;
}

