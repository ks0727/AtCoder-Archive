#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    multiset<int> st;
    rep(i,n-k){
        st.insert(a[i]);
    }
    int ans = *st.rbegin() - *st.begin();
    rep(i,k){
        st.erase(st.find(a[i]));
        st.insert(a[n-k+i]);
        ans = min(ans,*st.rbegin()-*st.begin());
    }
    cout << ans << endl;
    return 0;
}