#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll square(int a){
    return (ll)a*a;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,2*m-n) a.push_back(0);
    sort(a.begin(),a.end());
    ll ans = 0;
    rep(i,m){
        ans += square(a[i]+a[2*m-1-i]);
    }
    cout << ans << endl;
}