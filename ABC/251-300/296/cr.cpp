#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,x;
    cin >> n >> x;
    vector<ll> a(n);
    vector<ll> diff;
    bool ans = false;
    rep(i,n) cin >> a[i];
    if(x >= 0) sort(a.rbegin(),a.rend());
    else sort(a.begin(),a.end());
    rep(i,n){
        rep(j,n-i+1){
            diff.push_back(a[i] - a[j]);
        }
    }
    int size = diff.size();
    rep(i,size){
        if(x == diff[i]) ans = true;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
