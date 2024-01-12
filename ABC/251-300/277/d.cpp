#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    map<int,int> mp;
    set<int> st;
    ll sum = 0;
    rep(i,n){
        mp[a[i]]++;
        st.insert(a[i]);
        sum += (ll)a[i];
    }
    sort(a.begin(),a.end());
    int key = a[0];
    set<int> needTovisit;
    needTovisit.insert(key);
    rep(i,n){
        if(key == a[i]) continue;
        if(key + 1 == a[i]) continue;
        needTovisit.insert(a[i]);
        key = a[i];
    }
    if(!needTovisit.count(1) && needTovisit.size() != 1) needTovisit.erase(a[0]);
    auto calc = [&](int x, ll val){
        while(true){
            if(!st.count(x)) break;
            if(x == m-1){
                val -= (ll)mp[x]*x;
                x = 0;
            }else{
                val -= (ll)mp[x]*x;
                x++;
            }
        }
        return val;
    };

    ll ans = sum;
    for(int x : needTovisit){
        cout << x << endl;
        ll now = sum;
        now = calc(x,now);
        ans = min(ans,now);
    }
    cout << ans << endl;
    return 0;
}