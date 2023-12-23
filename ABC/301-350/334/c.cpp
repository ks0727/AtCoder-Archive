#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(k);
    rep(i,k) cin >> a[i];
    ll ans = 0;
    if(k%2 == 0){
        rep(i,k/2){
            ans += abs(a[i*2]-a[i*2+1]);
        }
    }else{
        vector<int> even(k/2),odd(k/2);
        for(int i=0;i<(k/2);i++){
            even[i] = abs(a[2*i]-a[2*i+1]);
            odd[i] = abs(a[2*i+1]-a[2*i+2]);
        }
        const ll INF = 1e18;
        ans = INF;
        ll sum = 0;
        rep(i,k/2) sum += odd[i];
        rep(i,even.size()){
            ans = min(ans,sum);
            sum -= odd[i];
            sum += even[i];
        }
        ans = min(ans,sum);
    }
    cout << ans << endl;
    return 0;
}