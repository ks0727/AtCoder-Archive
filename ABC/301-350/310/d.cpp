#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,t,m;
    cin >> n >> t >> m;
    set<P> ng;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        ng.insert(P(a,b));
        ng.insert(P(b,a));
    }
    int ans = 0;
    vector<vector<int> > groups;
    auto f = [&](auto f, int v)->void{
        if(v == n){
            if(groups.size() == t) ans++;
            return;
        }
        rep(i,groups.size()){
            bool canput = true;
            rep(j,groups[i].size()){
                if(ng.count(P(v,groups[i][j]))){
                    canput = false;
                    break;
                }
            }
                if(canput){
                    groups[i].push_back(v);
                    f(f,v+1);
                    groups[i].pop_back();
                }
        }
        groups.push_back(vector<int>(1,v));
        f(f,v+1);
        groups.pop_back();
    };
    f(f,0);
    cout << ans << endl;
    return 0;
}