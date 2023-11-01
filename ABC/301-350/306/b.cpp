#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll pow(int a, int b){
    ll ans = 1;
    rep(i,b){
        ans *= ll(a);
    }
    return ans;
}
int main(){
    vector<int> a(64);
    ll ans = 0;
    rep(i,64) cin >> a[i];
    rep(i,64){
        if(a[i] == 1){
            ans += pow(2,i);
        }
    }
    cout << ans << endl;
}