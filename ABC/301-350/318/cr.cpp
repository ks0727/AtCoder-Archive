#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,d,p;
    cin >> n >> d >> p;
    ll ans = 0;
    vector<ll> f(n);
    rep(i,n){
        cin >> f[i];
        ans += f[i];
    } 
    sort(f.rbegin(),f.rend());
    for(int i=1;i <= n/d+1;i++){
        ll sum_f = ans;
        for(int j=d*i;j<(n);j++){
            sum_f += f[j];
        }
        ans = min(ans,sum_f+(ll)p*i);
    }
    cout << ans << endl;
}