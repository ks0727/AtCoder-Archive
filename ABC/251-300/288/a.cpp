#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> ans;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        ll sum = ll(a+b);
        ans.push_back(sum);
    }
    rep(i,n){
        cout << ans[i] << endl;
    }
    return 0;
}