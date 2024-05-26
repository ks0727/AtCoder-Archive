#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
using ll = long long;
int main(){
    int n;
    cin >> n;
    priority_queue<P,vector<P>,greater<P> > q;
    vector<P> ps;
    rep(i,n){
        int l,r;
        cin >> l >> r;
        ps.push_back(P(l,r));
    }
    sort(ps.begin(),ps.end());
    rep(i,n){
        q.emplace(ps[i].first,-i);
        q.emplace(ps[i].second,-i);
    }
    set<int> st;
    ll ans = 0;
    while(!q.empty()){
        auto[x,idx] = q.top(); q.pop();
        if(st.count(idx)){
            st.erase(idx);
        }else{
            ans += st.size();
            st.insert(idx);
        }
    }
    cout << ans << endl;
    return 0;
}