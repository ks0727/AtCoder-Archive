#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll c2(int x){
    return (ll)x*(x-1)/2;
}
int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int aij = 0, aji = 0;
    vector<bool> seen(n);
    rep(i,n){
        if(seen[i]) continue;
        if(a[i] == i+1){
            aij++;
            seen[i] = true;
        } 
        if(a[i] != i+1){
            int j = a[i];
            if(a[j-1] == i+1){
                aji++;
                a[i] = true;
                a[j-1] = true;
            }
        }
    }
    ll ans = c2(aij);
    ans += aji;
    cout << ans << endl;
    return 0;
}