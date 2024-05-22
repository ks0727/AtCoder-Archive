#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    string s;
    cin >> s;
    ll ans = 0;
    vector<int> m(3),x(3);
    rep(k,n) if(s[k] == 'X') x[a[k]]++;
    auto mex = [&](int a,int b,int c){
        int s = 1<<a|1<<b|1<<c;
        int res = 0;
        while((s>>res)&1) res++;
        return res;
    };
    rep(j,n){
        if(s[j] == 'E'){
            rep(i,3)rep(k,3){
                ll now = (ll)m[i]*x[k];
                ans += now*mex(i,a[j],k);
            }
        }
        if(s[j] == 'M') m[a[j]]++;
        if(s[j] == 'X') x[a[j]]--;
    }
    return 0;
}