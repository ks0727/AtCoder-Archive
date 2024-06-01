#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> x(q);
    rep(qi,q) cin >> x[qi],x[qi]--;
    vector<vector<int> > del(n);
    rep(qi,q){
        del[x[qi]].push_back(qi);
    }
    rep(i,n){
        if(del[i].size()%2){
            del[i].push_back(q);
        }
        sort(del[i].begin(),del[i].end());
    }
    set<int> st;
    vector<ll> sz(q);
    rep(qi,q){
        if(st.count(x[qi])){
            st.erase(x[qi]);
        }else{
            st.insert(x[qi]);
        }
        sz[qi] = st.size();
    }
    vector<ll> s(q+1);
    rep(qi,q) s[qi+1] = s[qi]+sz[qi];
    vector<ll> ans(n);
    rep(i,n){
        for(int j=0;j<del[i].size();j+=2){
            ans[i] += s[del[i][j+1]] - s[del[i][j]];
        }
    }
    rep(i,n) cout << ans[i] << ' '; cout << endl;
    return 0;
}