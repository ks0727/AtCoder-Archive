#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    set<int> s;
    vector<int> cnt(n+1);
    rep(i,n+1) s.insert(i);
    auto add = [&](int x){
        if(x > n) return;
        if(cnt[x] == 0) s.erase(x);
        cnt[x]++;
    };
    auto del = [&](int x){
        if(x > n) return;
        cnt[x]--;
        if(cnt[x] == 0) s.insert(x);
    };
    rep(i,n) add(a[i]);
    rep(qi,q){
        int i,x;
        cin >> i >> x;
        i--;
        del(a[i]);
        a[i] = x;
        add(a[i]);
        cout << *s.begin() << '\n';
    }
    return 0;
}