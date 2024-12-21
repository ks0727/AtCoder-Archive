#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n; long long s;
    cin >> n >> s;
    vector<long long> a(n);
    rep(i,n) cin >> a[i];
    vector<long long> b(2*n);
    rep(i,n){
        b[i] = a[i];
        b[i+n] = a[i];
    }
    vector<long long> sa(2*n+1);
    rep(i,2*n) sa[i+1] = sa[i] + b[i];
    s %= sa[n];
    //rep(i,2*n) cout << sa[i] << ' '; cout << endl;
    rep(i,2*n){
        long long now = sa[i];
        long long nxt = now + s;
        auto it = lower_bound(sa.begin(),sa.end(),nxt);
        if(*it == nxt){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}