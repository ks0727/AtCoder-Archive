#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    map<ll,int> mp;
    rep(i,n){
        mp[a[i]]++;
    }
    vector<ll> ans;
    ll temp = 0;
    int j = 0;
    for(auto [value,cnt] : mp){
        temp += (ll)value*cnt;
        ans.push_back(temp);
    }

    vector<ll> b= a;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    rep(i,n){
        int v = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
        cout << ans[mp.size()-1] - ans[v] << ' ';
    }
    return 0;
}