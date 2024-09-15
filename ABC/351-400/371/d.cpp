#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> x(n),p(n),s(n+1);
    rep(i,n) cin >> x[i];
    rep(i,n) cin >> p[i];
    rep(i,n) s[i+1] = s[i] + p[i];
    int q;
    cin >> q;
    while(q--){
        ll l,r;
        cin >> l >> r;
        int ri = upper_bound(x.begin(),x.end(),r) - x.begin();
        int li = lower_bound(x.begin(),x.end(),l) - x.begin();
        //cout << li << ' ' << ri << endl;
        //if(li != 0) li--;
        cout << s[ri] - s[li] << endl;
    }
    return 0;
}