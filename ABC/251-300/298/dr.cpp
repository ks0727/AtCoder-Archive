#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

int main(){
    int Q;
    cin >> Q;
    queue<char> q;
    mint ans = 1;
    q.push('1');
    rep(i,Q){
        int type;
        cin >> type;
        if(type == 1){
            char x;
            cin >> x;
            q.push(x);
            ans *= 10;
            ans += x - '0';
        }
        if(type == 2){
            int x = q.front() - '0'; q.pop();
            int n = q.size();
            ans -= mint(x)*mint(10).pow(n);
        }
        if(type == 3){
            cout << ans.val() << '\n';
        }
    }
    return 0;
}