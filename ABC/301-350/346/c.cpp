#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n; ll k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll ans = k*(k+1)/2;
    set<int> st;
    rep(i,n){
        if(a[i] <= k){
            if(!st.count(a[i])){
                ans -= a[i];
                st.insert(a[i]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}