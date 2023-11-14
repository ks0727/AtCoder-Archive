#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

int main(){
    mint s = 1;
    int q;
    cin >> q;
    rep(qi,q){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            cin >> x;
            s = s * 10 + x;
        }else if(type == 2){
            mint t = s;
            int digit  = 0;
            while(t.val() >= 10){
                t /= 10;
                digit++;
            }
            s %= mint(10).pow(digit);
        }else{
            cout << s.val() << endl;
        }
    }
    return 0;
}