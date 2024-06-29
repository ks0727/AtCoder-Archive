#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll c2(int x){
    return (ll)x*(x+1)/2;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i],a[i]--;

    vector<vector<int> > cnt(n);
    rep(i,n){
        cnt[a[i]].push_back(i);
    }
    ll ans = 0;
    rep(i,n){
        if(cnt[i].size() < 2) continue;
        ll s = 0;
        rep(j,cnt[i].size()){
            if(j == 0) continue;
            s += (ll)(j)*(cnt[i][j] - cnt[i][j-1]);
            ans += s;
            ans -= c2(j);
        }
    }
    cout <<  ans << endl;
    return 0;
}