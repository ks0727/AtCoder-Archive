#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;
using P = pair<int,int>;

int main(){
    int n,k;
    cin >> n >> k;
    mint in = (mint)1/(n*n);
    mint p = in + (n-1)*(n-1)*in;
    mint q = 1 - p;

    mint zero = 1;
    mint other = 0;

    rep(i,k){
        mint zero_c = zero;
        mint other_c = other;
        zero = p*zero_c + q*other_c;
        other = p*other_c + 2*in*zero_c;
        if(n>=3) other += other_c*2*in*(n-2);
    }
    mint ans = zero;
    mint s = n*(n+1)/2 -1;
    ans += s*other;
    cout << ans.val() << endl;
    return 0;
}