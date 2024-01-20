#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

int main(){
    int n,P;
    cin >> n >> P;
    mint p = mint(P)/100;
    mint q = 1 - p;
    auto f = [&](auto f, int i)->mint{
        if(i <= 0) return 1;
        else return 1 + p * f(f,i-2) + q * f(f,i-1);
    };
    cout << f(f,n).val() - 1 << endl;
    return 0;
}