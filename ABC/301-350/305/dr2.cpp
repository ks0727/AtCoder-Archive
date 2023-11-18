#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> s(n+1);
    rep(i,n){
        s[i+1] = s[i];
        if(i == 0) continue;
        if(i%2 == 0) s[i+1] += a[i] - a[i-1];
    }
    cout << endl;
    int q;
    cin >> q;
    auto f = [&](int v){
        int index = lower_bound(a.begin(),a.end(),v) - a.begin();
        index--;
        ll ans = s[index+1];
        if(index%2 == 1){
            ans += v - a[index];
        }
        return ans;
    };
    rep(qi,q){
        int l,r;
        cin >> l >> r;
        cout << f(r) - f(l) << endl;
    }
    return 0;
}