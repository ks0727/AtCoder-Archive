#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> s(n);
    for(int i=1;i<(n);++i){
        s[i] = s[i-1];
        if(i % 2 == 0) s[i] += a[i] - a[i-1];
    }

    auto f = [&](int x){
        int i = lower_bound(a.begin(),a.end(),x) - a.begin() - 1;
        if(i < 0) return 0;
        int res = s[i];
        if(i%2 == 1) res += x - a[i];
        return res;
    };

    int q;
    cin >> q;
    rep(qi,q){
        int l,r;
        cin >> l >> r;
        int ans = f(r) - f(l);
        cout << ans << '\n';
    }
    return 0;
}