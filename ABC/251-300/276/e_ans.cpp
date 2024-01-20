#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)

const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    int n = h*w;
    dsu uf(n);
    auto toId = [&](int i,int j){
        return i*w+j;
    };
    rep(i,h)rep(j,w){
        if(s[i][j] != '.') continue;
        if(j+1 < w && s[i][j+1] == '.'){
            uf.merge(toId(i,j),toId(i,j+1));
        }
        if(i+1 < h && s[i+1][j] == '.'){
            uf.merge(toId(i,j),toId(i+1,j));
        }
    }
    rep(i,h)rep(j,w){
        if(s[i][j] == 'S'){
            set<int> st; int cnt = 0;
            rep(v,4){
                int ni = i + di[v];
                int nj = j + dj[v];
                if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                if(s[ni][nj] != '.') continue;
                st.insert(uf.leader(toId(ni,nj)));
                cnt++;
            }
            if(st.size() == cnt) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }

    return 0;
}