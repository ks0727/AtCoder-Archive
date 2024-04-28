#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<vector<bool> > adj(h,vector<bool>(w));
    //上下左右いずれかが磁石であるマスを記録しておく
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#') continue;
            rep(d,4){
                int ni = i+di[d]; int nj = j+dj[d];
                if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                if(s[ni][nj] == '#'){
                    adj[i][j] = true;
                    break;
                }
            }
        }
    }
    dsu uf(h*w);
    auto toid = [&](int i, int j){
        return i*w+j;
    };
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#') continue;
            if(adj[i][j]) continue;
            rep(d,4){
                int ni = i+di[d]; int nj = j+dj[d];
                if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                if(s[ni][nj] == '#') continue;
                if(adj[ni][nj]) continue;
                //cout << i << ' ' << j << ' ' << ni << ' ' << nj << endl;
                //cout << toid(i,j) << ' ' << toid(ni,nj) << endl;
                if(!uf.same(toid(i,j),toid(ni,nj))) uf.merge(toid(i,j),toid(ni,nj));
            }
        }
    }
    // rep(i,h){
    //     rep(j,w){
    //         cout << uf.leader(toid(i,j)) << ' ';
    //     }
    //     cout << endl;
    // }
    vector<int> val(h*w);
    rep(i,h){
        rep(j,w){
            if(!adj[i][j]) continue;
            set<int> st;
            rep(d,4){
                int ni = i+di[d]; int nj = j+dj[d];
                if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                if(s[ni][nj] == '#') continue;
                if(adj[ni][nj]) continue;
                int nid = toid(ni,nj);
                if(!st.count(uf.leader(nid))){ //1種類の連結成分には1回ずつしか足さない
                    val[uf.leader(nid)]++;
                    st.insert(uf.leader(nid));
                }
            }
        }
    }
    int ans = 0;
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#') continue;
            int id = toid(i,j);
            int sz = uf.size(id);
            ans = max(ans,sz+val[id]);
        }
    }
    cout << ans << endl;
    return 0;
}