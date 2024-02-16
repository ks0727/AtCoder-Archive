#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    vector<P> p;
    rep(i,4){
        int x,y;
        cin >> x >> y;
        p.emplace_back(x,y);
    }
    auto make_vec = [&](P a, P b){
        return P(b.first-a.first,b.second-a.second); 
    };
    auto dot_product = [&](P a, P b){
        return a.first*b.first + a.second*b.second;
    };
    P ab = make_vec(p[0],p[1]);
    P ad = make_vec(p[0],p[3]);
    P bc = make_vec(p[1],p[2]);
    P ba = make_vec(p[1],p[0]);
    P cd = make_vec(p[2],p[3]);
    P cb = make_vec(p[2],p[1]);
    P da = make_vec(p[3],p[0]);
    P dc = make_vec(p[3],p[2]);
    bool ans = true;
    if(dot_product(ab,da) < 0) ans = false;
    if(dot_product(bc,ab) < 0) ans = false;
    if(dot_product(cd,bc) < 0) ans = false;
    if(dot_product(da,cd) < 0) ans = false;
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
} 