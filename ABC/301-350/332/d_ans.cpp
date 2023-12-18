#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using vvi = vector<vector<int> >;

int main(){
    int h,w;
    cin >> h >> w;
    vvi a(h,vector<int>(w)),b(h,vector<int>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    rep(i,h)rep(j,w) cin >> b[i][j];

    queue<vvi> q;
    map<vvi,int> dist;
    auto push = [&](vvi& s ,int d){
        if(dist.count(s)) return;
        dist[s] = d;
        q.push(s);
    };
    push(a,0);
    while(!q.empty()){
        vvi s = q.front(); q.pop();
        int d = dist[s];
        rep(i,h-1){
            vvi ns = s;
            swap(ns[i],ns[i+1]);
            push(ns,d+1);
        }
        rep(j,w-1){
            vvi ns = s;
            rep(i,h) swap(ns[i][j],ns[i][j+1]);
            push(ns,d+1);
        }
    }
    if(dist.count(b)) cout << dist[b] << endl;
    else cout << -1 << endl;
    return 0;
}