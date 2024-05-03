#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

mint memo[101][101][2];
bool visited[101][101][2];

int main(){
    int n,a,b,p,q;
    cin >> n >> a >> b >> p >> q;
    mint ip = mint(1)/p;
    mint iq = mint(1)/q;

    auto f = [&](auto f, int a, int b, int t)->mint{
        if(a >= n) return 1;
        if(b >= n) return 0;
        if(visited[a][b][t]) return memo[a][b][t];
        if(t == 0){
            mint res = 0;
            for(int i=1;i<=p;i++){
                res += f(f,a+i,b,1);
            }
            res *= ip;
        }else{
            mint res = 0;
            for(int i=1;i<=q;i++){
                res += f(f,a,b+i,0);
            }
            res *= iq;
        }
        visited[a][b][t] = true;
        return memo[101][101][2] = res;
    };
    cout << f(f,a,b,0).val() << endl;
    return 0;
}