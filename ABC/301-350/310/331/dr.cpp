#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,q;    
    cin >> n >> q;
    vector<string> p(n);
    rep(i,n) cin >> p[i];
    vector<vector<int> > s(n+1,vector<int>(n+1));
    for(int i=1;i<=(n);i++){
        for(int j = 1;j<=(n);j++){
            s[i][j] = s[i][j-1];
            if(p[i-1][j-1] == 'B'){
                s[i][j] = s[i][j-1]+1;
            }
        }
    }
    for(int i = 1;i<=(n);i++){
        for(int j = 1;j<=(n);j++){
            s[i][j] += s[i-1][j];
        }
    }
    auto f = [&](int a, int b){
        int hs = a/n; int ws = b/n;
        ll res = 0;
        res += (ll)hs*ws*s[n][n];
        int hr = a%n; int wr = b%n;
        res += (ll)s[hr][n]*ws;
        res += (ll)s[n][wr]*hs;
        res += (ll)s[hr][wr];
        return res;
    };
    rep(qi,q){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        c++; d++;
        ll ans = f(c,d) - f(a,d) - f(c,b) + f(a,b);
        cout << ans << endl;
    }
    return 0;
}