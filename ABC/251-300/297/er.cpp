#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    set<ll> st;
    st.insert(0);
    rep(i,k){
        ll mn = *st.begin();
        st.erase(mn);
        rep(j,n) st.insert((ll)mn+a[j]);
    }
    cout << *st.begin() << endl;
    return 0;
}