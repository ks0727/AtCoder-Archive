#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    const int M = 1000005;
    vector<vector<int> > is(M);
    rep(i,n) is[a[i]].push_back(i);
    vector<ll> ans(n);
    ll now = 0;
    for(int x = M-1;x>=1;x--){
        for(int i : is[x]) ans[i] = now;
        now += (ll)x * is[x].size();
    }
    rep(i,n) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}