#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
ll dp[21][10][2][2];
int main(){
    string l,r;
    cin >> l >> r;
    reverse(l.begin(),l.end());
    reverse(r.begin(),r.end());
    while(l.size() != 20) l += '0';
    while(r.size() != 20) r += '0';
    reverse(l.begin(),l.end());
    reverse(r.begin(),r.end());
    ll ans = 0;
    
    auto f = [&](auto f, int d, int last, ll now, bool ok = false, string s)->ll{
        if(d == s.size()){
            if(ok) return now;
        }
        ll res = 0;
        for(int i=last;i>=0;i--){
            res += f(f,d+1,i,now,)
        }
    };
    cout << ans << endl;
    return 0;
}