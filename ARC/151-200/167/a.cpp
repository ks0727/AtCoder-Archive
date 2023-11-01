#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,ll>;

ll square(ll a){
    return (ll)a*a;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    int basic = n/m;
    vector<int> b(m,basic);
    int rest = n%m;
    rep(i,rest) b[i] = 2;
    sort(b.rbegin(),b.rend());
    vector<bool> seen(n);
    vector<P> ans;
    rep(i,m){
        if(b[i] == 2){
            ans.push_back({a[(n-2)/2 - i],a[(n-2)/2 + 1 + i]});
            seen[(n-2)/2 - i] = true;
            seen[(n-2)/2 + 1 + i] = true;
        }
    }
    ll output = 0;
    rep(i,ans.size()){
        output += square(ans[i].first+ans[i].second);
    }
    rep(i,n){
        if(!seen[i]){
            output += square(a[i]);
        }
    }
    cout << output << endl;
    return 0;
}