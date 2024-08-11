#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

const int M = 1e6;
vector<ll> f(vector<int> x){
    int n = x.size();
    rep(i,n) x[i] += M*2; //下駄を履かせる(負の数をなくす)
    ll s = 0;
    rep(i,n) s += x[i];
    vector<ll> res(4*M+1);
    res[0] = s;

    int k = 0;
    sort(x.begin(),x.end());
    for(int i=1;i<=M*4;i++){
        while(k < n && x[k] < i) k++;
        s-= n-k*2;
        res[i] = s;
    }
    return res;
}

int main(){
    int n,d;
    cin >> n >> d;
    vector<int> x(n),y(n);
    rep(i,n) cin >> x[i] >> y[i];

    vector<ll> a = f(x);
    vector<ll> b = f(y);

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    ll ans = 0;
    int r = b.size()-1;
    rep(l,a.size()){
        while(r >= 0 && a[l]+b[r] > d) r--;
        ans += r+1;
    }
    return 0;
}