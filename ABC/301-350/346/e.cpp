#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    int h,w,m;
    cin >> h >> w >> m;
    vector<int> t(m),a(m),x(m);
    rep(i,m) cin >> t[i] >> a[i] >> x[i];
    int rh = h, rw = w;
    vector<ll> ans(2e5+5);
    vector<bool> row(h),col(w);
    for(int i=m-1;i>=0;i--){
        if(t[i] == 1){
            if(rw == 0) continue;
            if(row[a[i]-1]) continue;
            row[a[i]-1] = true;
            ans[x[i]] += rw;
            rh--;
        }else{
            if(rw == 0) continue;
            if(col[a[i]-1]) continue;
            ans[x[i]] += rh;
            col[a[i]-1] = true;
            rw--;
        }
    }
    ll sum = 0; ll k = 0;
    bool sumzero = false;
    rep(i,2e5+5){
        if(i==0 && ans[i] == 0) sumzero = true;
        if(ans[i] != 0) k++;
        sum += ans[i];
    } 
    ans[0] += (ll)h*w - sum;
    if(sumzero && ans[0] > 0) k++;
    cout << k << endl;
    rep(i,2e5+2){
        if(ans[i] == 0) continue;
        cout <<i << ' ' <<  ans[i] << '\n';
    }
    return 0;
}