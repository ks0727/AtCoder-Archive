#include <iostream>
using namespace std;

long long sum(int x){
  return x*(x+1)/2;
}
int main(){
  int r,g,b;
  cin >> r >> g >>b;
  long long ans = 1e18;
  for(int i=-600;i<=-100;i++){
    for(int j=0;j<g;j++){
      for(int k=0;k<b;k++){
        int il = r-i; int ir = i;
        int jl = g-j; int jr = j;
        int kl = b-k; int kr = k;
        if(ir-100 >= -jl) continue;
        if(jr >= 100-kl) continue;
        long long now = 0;
        now += sum(il);
        now += sum(ir);
        now += sum(jl);
        now += sum(jl);
        now += sum(kl);
        now += sum(kr);
        ans = min(ans,now);
      }
    }
  }
  cout << ans << endl;
  return 0;
}

