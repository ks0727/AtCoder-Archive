#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll sum = 0;
    vector<int> b;
    vector<int> cnt(n);
    for(int i=n-1;i>=0;i--){
        if(i != n-1){
            int idx = lower_bound(b.begin(),b.end(),a[i])-b.begin();
            cnt[i] = idx;
        }
        b.push_back(a[i]);
        sort(b.begin(),b.end());
    }
    rep(i,n){
        sum += a[i]*i;
        sum -= a[i]*(n-1-i);
    }
    rep(i,n){
        sum += (ll)a[i]*cnt[i];
    }
    cout << sum << endl;
    return 0;
}