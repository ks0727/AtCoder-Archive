#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
const int M = 200005;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> pos(M,-1); //ある値とその位置
    ll ans = 0;
    ll sub = 0;
    rep(i,n){
        ans += (ll)(i+1)*(i+2)/2;
        if(pos[a[i]] != -1){
            sub += (ll)pos[a[i]]+1;
        }
        ans -= sub;
        pos[a[i]] = i;
    }
    cout << ans << endl;
    return 0;
}