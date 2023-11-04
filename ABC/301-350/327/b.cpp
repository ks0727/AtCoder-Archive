#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll aa(int a){
    ll ans = a;
    rep(i,a-1){
        ans *= (ll)a;
    }
    return ans;
}

int main(){
    ll b;
    cin >> b;
    vector<ll> a;
    rep(i,16){
        a.push_back(aa(i));
    }
    rep(i,16){
        if(b == a[i]){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}