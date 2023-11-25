#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll d;
    cin >> d;
    vector<ll> ss;
    for(int i=0;i<=1e7;i++){
        ss.push_back((ll)i*i);
    }
    int n = ss.size();
    const ll INF = 1e18;
    ll ans = INF;
    rep(i,n){
        if(i == 0) continue;
        ll target = d - ss[i];
        int index = lower_bound(ss.begin(),ss.end(),target) - ss.begin();
        ans = min(abs(ss[index]-target),ans);
        if(index > 1) ans = min(abs(ss[index-1]-target),ans);
    }
    cout << ans << endl;
    return 0;
}