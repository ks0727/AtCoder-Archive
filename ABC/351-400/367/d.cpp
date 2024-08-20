#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> s(2*n+1);
    rep(i,n*2){
        if(i < n) s[i+1] = s[i] + a[i];
        else s[i+1] = s[i] + a[i-n]; 
    } 
    rep(i,n*2) s[i] %= m;
    map<int,vector<int> > mp;
    rep(i,n*2){
        mp[s[i]].push_back(i);
    } 
    ll ans = 0;
    for(auto [rest,arr] : mp){
        int r = 0;
        rep(l,arr.size()){
            if(arr[l] >= n) break;
            while(r < arr.size() && arr[r] - arr[l] < n) r++;
            r--;
            ans += r-l;
        }
    }
    cout << ans << endl;
    return 0;
}