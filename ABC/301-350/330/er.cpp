#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    set<int> st;
    map<int,int> mp;
    rep(i,n){
        mp[a[i]]++;
    }
    rep(i,n+1) st.insert(i);
    rep(i,n) st.erase(a[i]);
    rep(qi,q){
        int i,x;
        cin >> i >> x;
        i--;
        mp[a[i]]--;
        mp[x]++;
        if(mp[a[i]] == 0) st.insert(a[i]);
        a[i] = x;
        st.erase(x);
        cout << *st.begin() << endl;
    }
    return 0;
}