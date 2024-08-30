#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    sort(s.begin(),s.end());
    vector<int> h(n);
    rep(i,n-1){
        int sz = min(s[i].size(),s[i+1].size());
        int x = 0;
        rep(j,sz){
            if(s[i][j] != s[i+1][j]) break;
            x++;
        }
        h[i] = x;
    }
    ll ans = 0;
    ll add = s[0].size();
    stack<pair<int,int> > st;
    st.emplace(s[0].size(),1);
    for(int i=0;i<n-1;++i){
        int nw = 0;
        while(!st.empty() && st.top().first >= h[i]){
            add -= (ll)st.top().first*st.top().second;
            nw += st.top().second;
            st.pop();
        }
        if(nw > 0){
            add += (ll)nw*h[i];
            st.emplace(h[i],nw);
        }
        ans += add;
        st.emplace(s[i+1].size(),1);
        add += s[i+1].size();
    }
    cout << ans << endl;
    return 0;
}