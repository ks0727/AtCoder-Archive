#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,s,m,l;
    cin >> n >> s >> m >> l;
    const int INF = 1e9;
    int ans = 1e9;
    rep(ns,18){
        rep(nl,18){
            rep(nm,18){
                if(ns*6+nm*8+nl*12 < n) continue;
                int price = ns*s+nl*l+nm*m;
                ans = min(ans,price); 
            }
        }
    }
    cout << ans << endl;
    return 0;
}