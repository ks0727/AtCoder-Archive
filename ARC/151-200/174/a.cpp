#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n; ll c;
    cin >> n >> c;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> s(n+1);
    rep(i,n) s[i+1] = a[i] + s[i];
    ll mn = s[0]; ll mx = s[0];
    ll diff = 0;
    if(c > 0){
        for(int i=1;i<=(n);i++){
            if(s[i] > mn){ //最小値よりも大きい値がきたら差をとる
                diff = max(diff,s[i]-mn); 
            }
            if(s[i] < mn){ //最小値よりも小さい値がきたら最小値を更新
                mn = s[i];
            }
        }
    }else{
        for(int i=1;i<=(n);i++){
            if(s[i] < mx){ //最大値よりも小さい値がきたら差をとる
                diff = min(diff,s[i]-mx); 
            }
            if(s[i] > mx){ //最大値よりも大きい値がきたら最大値を更新
                mx = s[i];
            }
        }
    }
    ll ans = s[n];
    ans += diff*(c-1);
    cout << ans << endl;
    return 0;
}