#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

int main(){
    int n,q;
    cin >> n >> q;
    vector<P> ps;
    rep(i,n) ps.emplace_back(i+1,0);
    reverse(ps.begin(),ps.end());
    map<char,int> mp = {{'L',0},{'R',2},{'U',3},{'D',1}};

    rep(qi,q){
        int type;
        cin >> type;
        if(type == 1){
            char c; cin >> c;
            int v = mp[c];
            auto [x,y] = ps.back();
            ps.emplace_back(x+dx[v],y+dy[v]);
        }else{
            int p; cin >> p;
            auto [x,y] = ps[ps.size()-p];
            cout << x << ' ' << y << '\n';
        }
    }
    return 0;
}