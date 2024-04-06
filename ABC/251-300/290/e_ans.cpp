#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll c2(ll n){
    return n*(n-1)/2;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) a[i]--;
    vector<int> cnt(n);
    rep(i,n) cnt[a[i]]++;
    ll same = 0;
    rep(i,n) same += c2(cnt[i]);
    ll ans = 0;
    auto del = [&](int x){

        same -= c2(cnt[x]);
        cnt[x]--;
        same += c2(cnt[x]);
    };
    rep(i,n){
        int l = i; int r = n-1-i;
        if(l >= r) break;
        ans += c2(r-l+1)-same;
        del(a[l]); del(a[r]);
    }
    cout << ans << endl;
    return 0;
}