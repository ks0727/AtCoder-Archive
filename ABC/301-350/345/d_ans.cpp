#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,h,w;
    cin >> n >> h >> w;
    vector<P> ab(n);
    rep(i,n) cin >> ab[i].first >> ab[i].second;
    auto dfs = [&](auto dfs,vector<string> s,vector<int> used)->bool{
        int si = -1,sj = -1;
        rep(i,h)rep(j,w){
            if(s[i][j] == '.' && si == -1){
                si = i; sj = j;
                break;
            }
        }
        if(si == -1){
            cout << "Yes" << endl;
            rep(i,h) cerr << s[i] << endl;
            return true;
        }
        rep(ri,n){
            if(used[ri]) continue;
            auto [a,b] = ab[ri];
            rep(bi,2){
                swap(a,b);
                if(si+a>h||sj+b>w)continue;
                bool ok = true;
                vector<string> ns = s;
                rep(i,a)rep(j,b){
                    if(ns[si+i][sj+j] != '.') ok = false;
                    ns[si+i][sj+j] = '1'+ri;
                }
                if(!ok) continue;
                used[ri] = 1;
                if(dfs(dfs,ns,used)) return true;
                used[ri] = 0;
            }
        }
        return false;
    };
    if(!dfs(dfs,vector<string>(h,string(w,'.')),vector<int>(n))) {
        cout << "No" << endl;
    }
}