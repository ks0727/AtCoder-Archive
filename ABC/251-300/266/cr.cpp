#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    vector<P> ps;
    rep(i,4){
        int x,y;
        cin >> x >> y;
        ps.emplace_back(x,y);
    }
    auto mkvec = [&](P a, P b){
        P res = P(b.first-a.first,b.second-a.second);
        return res;
    };
    auto revec = [&](P a){
        P res = P(-a.first,-a.second);
        return res;
    };
    auto cross_product = [&](P a, P b){
        int res = 0;
        res = a.first*b.second - a.second*b.first;
        return res;
    };
    P ab = mkvec(ps[0],ps[1]);
    P bc = mkvec(ps[1],ps[2]);
    P cd = mkvec(ps[2],ps[3]);
    P da = mkvec(ps[3],ps[0]);
    bool ans = true;
    if(cross_product(ab,revec(da)) < 0) ans = false;
    if(cross_product(bc,revec(ab))< 0) ans = false;
    if(cross_product(cd,revec(bc)) < 0) ans = false;
    if(cross_product(da,revec(cd)) < 0) ans = false;
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}