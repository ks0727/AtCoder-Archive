#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

struct grid{
    int h,w;
    vector<vector<int> > g;
    void input(){
        g = vector<vector<int> >(h,vector<int>(w));
        rep(i,h)rep(j,w) cin >> g[i][j];
    }
    bool same(grid c){
        vector<int> dist1,dist2;
        rep(i,h){
            rep(j,w){
                dist1.push_back(g[i][j]);
                dist2.push_back(c.g[i][j]);
            }
        }
        sort(dist1.begin(),dist1.end());
        sort(dist2.begin(),dist2.end());
        if(dist1 == dist2) return true;
        else return false;
    }
    void print(){
        rep(i,h){
            rep(j,w) cout << g[i][j] << ' ';
            cout << endl;
        }
    }
};

int main(){
    int h,w;
    cin >> h >> w;
    grid a,b;
    a.h = h; b.h = h;
    a.w = w; b.w = w;
    a.input();
    b.input();
    if(!a.same(b)){
        cout << -1 << endl;
        return 0;
    }
    if(a.g == b.g){
        cout << 0 << endl;
        return 0;
    }
    vector<int> rp,cp;
    rep(i,h) rp.push_back(i);
    rep(i,w) cp.push_back(i);
    int nr = 0,nc = 0,cnt=0;
    do{
        do{
            grid c = a;
            rep(i,h){
                rep(j,w){
                    c.g[i][j] = a.g[rp[i]][cp[j]];
                }
            }
            if(c.g == b.g){
                int nc = 0; int nr = 0;
                rep(i,h){
                    rep(j,h){
                        if(i < j && rp[i] > rp[j]) nr++;
                    }
                }
                rep(i,w){
                    rep(j,w){
                        if(i < j && cp[i] > cp[j]) nc++;
                    }
                }
                int ans = nr+nc;
                cout << ans << endl;
                return 0;
            }
        }while(next_permutation(cp.begin(),cp.end()));
    }while(next_permutation(rp.begin(),rp.end()));
    cout << -1 << endl;
    return 0;
}