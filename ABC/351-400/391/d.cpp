#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using T = tuple<int,int,int>;
int main(){
    int n,w;
    cin >> n >> w;
    const int INF = 1001001001;
    vector<queue<pair<int,int> > > cols(w);
    vector<T> ps;
    rep(i,n){
        int x,y;
        cin >> x >> y;
        x--; y--;
        ps.emplace_back(y,x,i);
    }
    sort(ps.begin(),ps.end());

    for(auto [y,x,idx] : ps) cols[x].emplace(y,idx);
    vector<int> ans(n,INF);

    bool ok = true;
    rep(i,w) if(cols[i].size() == 0) ok = false;

    if(ok){
        while(true){
            bool isdone = false;
            int mx = -1;
            rep(i,w){
                mx = max(mx,cols[i].front().first);
            }
            rep(i,w){
                ans[cols[i].front().second] = mx;
                cols[i].pop();
                if(cols[i].size() == 0) isdone = true;
            }
            if(isdone) break;
        }
    }
    //rep(i,n) cout << ans[i] << ' '; cout << endl;
    int q;
    cin >> q;
    while(q--){
        int t,a;
        cin >> t >> a;
        a--;
        if(ans[a] < t){
            cout << "No" << '\n';
        }else{
            cout << "Yes" << '\n';
        }
    }
    return 0;
}