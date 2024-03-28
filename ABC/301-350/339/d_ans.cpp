#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
using P2 = array<P,2>;
int di[4] = {-1,0,1,0};
int dj[4] = {0,1,0,-1};

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    P2 ps; int pi = 0;
    rep(i,n)rep(j,n) {
        if(s[i][j] == 'P'){     
            ps[pi++] = P(i,j);
        }
    }
    auto to_i = [&](P2 ps){
        int res = 0;
        res = res*n + ps[0].first;
        res = res*n + ps[0].second;
        res = res*n + ps[1].first;
        res = res*n + ps[1].second;
        return res;
    };
    auto to_ps = [&](int id){
        P2 ps;
        ps[1].second = id%n; id /= n;
        ps[1].first = id%n; id /= n;
        ps[0].second = id%n; id /= n;
        ps[0].first = id%n; id /= n;
        return ps;
    };
    int m = n*n*n*n;
    const int INF = 1001001001;
    vector<int> dist(m,INF);
    queue<int> q;
    int sid = to_i(ps);
    dist[sid] = 0;
    q.push(sid);
    while(!q.empty()){
        int id = q.front(); q.pop();
        int d = dist[id];
        P2 ps = to_ps(id);
        rep(v,4){
            P2 nps;
            rep(pi,2){
                auto [i,j] = ps[pi];
                int ni = i+di[v]; int nj = j+dj[v];
                if(ni < 0 || nj < 0 || ni >= n || nj >= n || s[ni][nj] == '#') {
                    ni = i; nj = j;
                }
                nps[pi] = P(ni,nj);
            }
            int nid = to_i(nps);
            if(dist[nid] != INF) continue;
            dist[nid] = d+1;
            q.push(nid);
        }
    }
    int ans = INF;
    rep(id,m){
        P2 ps = to_ps(id);
        int d = dist[id];
        if(ps[0] == ps[1]) ans = min(ans,d);
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}