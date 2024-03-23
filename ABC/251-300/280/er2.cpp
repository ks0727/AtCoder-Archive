#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

int main(){
    int n,p;
    cin >> n >> p;
    mint P = mint(p)/100;
    map<int,mint> mp;
    mp[0] = 0;
    auto f = [&](auto f,int x)->mint{
        if(x <= 0) return 0;
        if(mp.count(x)) return mp[x];
        else{
            mint res = 1 + mint(P)*f(f,x-2)+(mint)(1-P)*f(f,x-1);
            return mp[x] = res;
        }
    };
    mint ans = f(f,n);
    cout << ans.val() << endl;
    return 0;
}