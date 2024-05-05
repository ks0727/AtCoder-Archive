#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    rep(i,n) p[i]--;
    vector<int> idx(n);
    rep(i,n){
        idx[p[i]] = i;
    }
    int mx = -1,mn = 1e9;
    set<int> st;
    rep(i,k) st.insert(idx[i]);
    int ans = *st.rbegin()-*st.begin();
    rep(i,n-k){
        st.erase(idx[i]);
        st.insert(idx[i+k]);
        ans = min(ans,*st.rbegin()-*st.begin());
    }
    cout << ans << endl;
    return 0;
}