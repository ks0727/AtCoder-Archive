#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    int val = a[0];
    set<int> st;
    for(int i = 1; i*i<= val;++i){
        if(val%i != 0) continue;
        st.insert(i);
        st.insert(val/i);
    }
    set<int> er;
    for(int i = 1;i<n;++i){
        for(auto x : st){
            if(a[i] % x != 0 ) er.insert(x); 
        }
    }
    for(auto x : st){
        if(er.count(x)) continue;
        cout << x << endl;
    }
    return 0;
}