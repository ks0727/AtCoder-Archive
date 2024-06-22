#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
using ll = long long;

int main(){
    int h,w,n;
    cin >> h >> w >> n;
    vector<P> hs(n);
    const int INF = 1e9;
    vector s(h,vector<int>(w,INF));
    rep(i,n){
        int a,b;
        cin >> a >> b;
        a--; b--;
        hs[i] = P(a,b);
        s[a][b] = 0;
    }
    vector r(h,vector<int>(w));
    rep(i,h)rep(j,w){
        r[i][j] = min(h-i,w-j);
        assert(r[i][j] >= 0);
    }
    
    int m = max(h,w);
    set<int> st;
    for(int mi=1;mi<m;mi++){
        rep(hi,hs.size()){
            if(st.count(hi)) continue;
            auto [i,j] = hs[hi];
            bool ok = false;
            for(int ii=-mi;ii<=mi;ii++){
                for(int jj=-mi;jj<=mi;jj++){
                    if(abs(ii) != mi && abs(jj) != mi) continue;
                    int ni = i+ii; int nj = j+jj;
                    if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                    if(s[ni][nj] != INF) continue;
                    s[ni][nj] = mi;
                    ok = true;
                }
            }
            if(!ok) st.insert(hi);
        }
    }
    ll ans = 0;
    rep(i,h)rep(j,w){
        ans += min(r[i][j],s[i][j]);
    }
    cout << ans << endl;
    return 0;
}