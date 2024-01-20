#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> array(m);
    rep(i,m) array[i] = a[i];
    ll now = 0;
    sort(array.begin(),array.end());
    rep(i,k) now += (ll)array[i];
    vector<ll> ans(n-m+1);
    ans[0] = now;
    for(int i = m;i<(n);i++){
        int place = upper_bound(array.begin(),array.end(),a[i]) - array.begin();
        if(place > k){
            now -= array[0];
            now += array[k];
            array.insert(array.begin()+place,a[i]);
            array.erase(array.begin());
        }else{
            now -= array[0];
            now += a[i];
            array.insert(array.begin()+place,a[i]);
            array.erase(array.begin());
        }
        ans[i-m+1] = now;
    }
    rep(i,n-m+1){
        cout << ans[i] << ' ';
    }
    return 0;
}