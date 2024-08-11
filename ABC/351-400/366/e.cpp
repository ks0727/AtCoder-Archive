#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using P = pair<ll,ll>;

int main(){
    int n; ll d;
    cin >> n >> d;
    const ll INF = 1e18;
    vector<P> ps = {P(-INF,-INF),P(INF,INF),P(-INF,-INF),P(INF,INF)};
    rep(i,n){
        ll x,y;
        x += 1e6; y += 1e6;
        cin >> x >> y;
        if(ps[0].first < x-d){
            ps[0].first = x-d;
            ps[0].second = y;
        }
        if(ps[1].first > x+d){
            ps[1].first = x+d;
            ps[1].second = y;
        }
        if(ps[2].second < y-d){
            ps[2].first = x;
            ps[2].second = y-d;
        }
        if(ps[3].second > y+d){
            ps[3].first = x;
            ps[3].second = y+d;
        }
    }
    ll xmin = ps[0].first; ll xmax = ps[1].first;
    ll ymin = ps[2].second; ll ymax = ps[3].second;
    xmax-=n; xmin+=n; 
    ymax-=n; ymin+=n;
    if(ymax < ymin || xmax < xmin){
        cout << 0 << endl;
    }else{
        
    }
    return 0;
}