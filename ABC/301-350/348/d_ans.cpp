#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

struct Med{
    int r, c, e;
    Med(int r=0,int c=0,int e=0):r(r),c(c),e(e){}
};

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int si=0,sj=0,ti=0,tj=0;
    rep(i,h)rep(j,w){
        if(s[i][j] == 'S'){
            si=i; sj=j;
        }
        if(s[i][j] == 'T'){
            ti = i; tj = j;
        }
    }
    int n;
    cin >> n;
    vector<Med> meds(n);
    rep(i,n){
        int r,c,e;
        cin >> r >> c >> e;
        r--; c--;
        meds[i] = Med(r,c,e);
    }
    meds.emplace_back(si,sj,0);
    meds.emplace_back(ti,tj,0);
    n+=2;
    int sni =n-2, tni=n-1;
    const int INF = 1001001001;
    vector<vector<int> > to(n);
    rep(sv,n){
        auto [ir,ic,ie] = meds[sv];
        vector dist(h,vector<int>(w,INF));
        queue<P> q;
        dist[ir][ic] = 0;
        q.emplace(ir,ic);
        while (!q.empty())
        {
            auto [i,j] = q.front(); q.pop();
            rep(d,4){
                int ni=i+di[d]; int nj = j+dj[d];
                if(ni < 0 || nj < 0 || ni >=h||nj >=w) continue;
                if(s[ni][nj] == '#') continue;
                if(dist[ni][nj] != INF) continue;
                dist[ni][nj] = dist[i][j]+1;
                q.emplace(ni,nj);
            }
        }
        rep(v,n){ //その薬(sv)から行ける薬でグラフを作成する
            if(sv == v) continue;
            auto [r,c,e] = meds[v];
            if(dist[r][c] <= sv) to[sv].push_back(v);
        }
    }
    vector<int> dist(n,INF);
    queue<int> q;
    dist[sni] = 0; q.push(sni);
    while(!q.empty()){
        int v= q.front(); q.pop();
        for(int u : to[v]){
            if(dist[u] != INF) continue;
            dist[u] = dist[v]+1;
            q.push(u);
        }
    }
    if(dist[tni] != INF) cout << "Yes" << endl;
    else cout << "N" << endl;
    return 0;
}