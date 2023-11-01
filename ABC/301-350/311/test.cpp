#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > G(m);
    map<pair<int,int>,int> distance;
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
        distance[make_pair(a-1,b-1)] = c;
        distance[make_pair(b-1,a-1)] = c;
    }
    int current = 0;
    int mx = 0;
    vector<bool> seen(n);

    queue<P> q;
    q.emplace(0,1);
    seen[1] = true;

    while(!q.empty()){
        auto i = q.front();
        q.pop();
        int next_i = i;
            
            {
                passed[ni][nj] = true;
                ni += di[v];
                nj += dj[v];
            }
            ni -= di[v];
            nj -= dj[v];
            if(visited[ni][nj]) continue;
            visited[ni][nj] = true;
            q.emplace(ni,nj);
        }
    }
