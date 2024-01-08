#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    
    vector id(h,vector<int>(w,-1));
    int n = 0;
    rep(i,h)rep(j,w){
        if(s[i][j] == '#'){
            id[i][j] = n++;
        }
    }
    dsu uf(n);
    int base = n;
    rep(i,h)rep(j,w){
        if(s[i][j] == '#'){
            rep(v,4){
                int ni = i + di[v]; int nj = j + dj[v];
                if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                if(s[ni][nj] != '#') continue;
                int a = id[i][j]; int b = id[ni][nj];
                if(uf.same(a,b)) continue;
                base--;
                uf.merge(a,b);
            }
        }
    }
    mint sum = 0;
    int cnt = 0;
    rep(i,h)rep(j,w){
        if(s[i][j] != '#'){
            cnt++;
            int now = base;
            now++;
            set<int> st;
            rep(v,4){
                int ni = i + di[v]; int nj = j + dj[v];
                if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                if(s[ni][nj] != '#') continue;
                st.insert(uf.leader(id[ni][nj]));
            }
            now -= st.size();
            sum += now;
        }
    }
    mint ans = sum/cnt;
    return 0;
}