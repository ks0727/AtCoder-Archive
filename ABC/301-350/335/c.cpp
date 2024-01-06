#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,q;
    cin >> n >> q;
    vector<P> ps;
    rep(i,n){
        ps.emplace_back(i+1,0);
    }
    rep(qi,q){
        int type;
        cin >> type;
        if(type == 1){
            char c;
            cin >> c;
            P np = P(0,0);
            if(c == 'U'){
                np = P(ps[0].first,ps[0].second+1);
            }
            if(c == 'D'){
                np = P(ps[0].first,ps[0].second-1);
            }
            if(c == 'R'){
                np = P(ps[0].first+1,ps[0].second);
            }
            if(c == 'L'){
                np = P(ps[0].first-1,ps[0].second);
            }
            ps.pop_back();
            ps.insert(ps.begin(),np);
        }else{
            int p;
            cin >> p;
            p--;
            cout << ps[p].first << ' ' << ps[p].second << endl;
        }
    }
    return 0;
}