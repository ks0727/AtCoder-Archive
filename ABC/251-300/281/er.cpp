#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    multiset<int> s,l;
    ll now = 0;
    rep(i,m) s.insert(a[i]);
    rep(i,m-k){
        l.insert(*s.rbegin());
        s.erase(*s.rbegin());
    }
    for(int u : s) now += u;
    vector<ll> ans;
    ans.push_back(now);
    for(int i = m ; i <n;i++){
        if(s.count(a[i-m])){
            s.erase(s.find(a[i-m]));
        }else{
            l.erase(l.find(a[i-m]));
        }
        //削除がlで起こった時
        if(s.size() == k){
            if(a[i] < *s.rbegin()){
                now -= *s.rbegin();
                now += a[i];
                l.insert(*s.rbegin());
                s.erase(s.find(*s.rbegin()));
                s.insert(a[i]);
            }else{
                l.insert(a[i]);
            }
        }else{ //削除がsで起こった時
            now -= a[i-m];
            if(a[i] < *l.begin()){
                s.insert(a[i]);
                now += a[i];
            }else{
                now += *l.begin();
                s.insert(*l.begin());
                l.erase(l.begin());
                l.insert(a[i]);
            }
        }
        ans.push_back(now);
    }
    rep(i,ans.size()){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}