#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<int,int>;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int offset = 0;
    priority_queue<P,vector<P>,greater<P> > q;
    rep(i,n){
        while(!q.empty() && q.top().first < offset) q.pop();
        q.emplace(a[i]+q.size()+offset,i);
        offset++;
    }
    offset--;
    vector<int> ans(n);
    while(!q.empty()){
        auto [val,idx] = q.top(); q.pop();
        ans[idx] = val - offset;
    }
    rep(i,n) cout << ans[i] << ' '; cout << endl;
    return 0;
}