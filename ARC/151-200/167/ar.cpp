#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll pow(ll a,int b){
    ll ans = 1;
    rep(i,b){
        ans *= a;
    }
    return ans;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,2*m-n){
        a.push_back(0);
    }
    sort(a.begin(),a.end());
    ll ans = 0;
    rep(i,m){
        ans += pow((ll)(a[i]+a[2*m-i-1]),2);
    }
    cout << ans << endl;
    return 0;
}