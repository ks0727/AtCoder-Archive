#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n; ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    auto e = a;
    sort(e.begin(),e.end());
    ll pre = 0;
    rep(i,n){
        ll r = n-i;
        ll num = r*(e[i]-pre);
        if(num <= k && i < n-1) {
            k -= num;
        }else{
            pre += k/r;
            rep(j,n){
                a[j] -= pre;
                if(a[j] < 0) a[j] = 0;
            }
            k %= r;
            rep(j,n){
                if(k > 0 && a[j] > 0){
                    a[j]--;
                    k--;
                }
            }
            break;
        }
        pre = e[i];
    }
    rep(i,n) cout << a[i] << ' ';
    cout << endl;
    return 0;
}