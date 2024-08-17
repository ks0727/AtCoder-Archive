#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

ll c2(int x){
    ll res = (ll)x*(x-1)/2;
    return res;
}

//約数のうち最大の平方数を求める

int main(){
    int n;
    cin >> n;
    //平方数の判定
    vector<bool> sq(n+1);
    for(int i = 1;i*i<=n;++i){
        sq[i*i] = true; 
    }
    vector<int> f(n+1);
    for(int i = 1; i <= n; ++i){
        int mx_d = 1;
        for(int j = 1 ; j*j <= i; j++){
            if(i % j != 0) continue;
            if(sq[j]) mx_d = max(j,mx_d);
            if(i / j != j && sq[i/j]) mx_d = max(i/j,mx_d);
        }
        f[i] = mx_d;
    }
    // 以下 a[i] == a[j]となる (i,j) の組を求める問題となる
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) a[i] = i / f[i];
    map<int,int> mp;
    for(int i=1;i<=n;++i){
        mp[a[i]]++;
    }

    ll ans = 0;
    for(auto [x,num] : mp){
        if(num != 1) ans += c2(num);
    }
    ans *= 2;
    ans += n;
    cout << ans << endl;
    return 0;
}