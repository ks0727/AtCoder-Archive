#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

int main(){
    int n,m;
    cin >> n >> m;
    mint ans1 = m;
    mint ans2 = m;
    if(n <= 3){
        rep(i,n-2) ans1 *= (m-1);
        cout << ans1.val() << endl;
        return 0;
    }else{
        rep(i,n-3){
            ans1 *= (m-1);
            ans2 *= (m-1);
        }
        ans1 *= (m-1);
        rep(i,2) ans2 *= (m-2);
        mint ans = ans1+ans2;
        cout << ans.val() << endl;
    }
    return 0;
}