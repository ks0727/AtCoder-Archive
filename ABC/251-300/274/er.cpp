#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<double,double>;

double calc_dist(P p1, P p2){
    auto [x1,y1] = p1;
    auto [x2,y2] = p2;
    double res = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return res;
};
string btos(int x){
    string res = "";
    while(x > 0){
        res += (x%2)+'0';
        x /= 2;
    }
    reverse(res.begin(),res.end());
    return res;
}
void chmin(double& a, double b){a = min(a,b);}
int main(){
    int n,m;
    cin >> n >> m;
    vector<P> pos;
    pos.emplace_back(0,0);
    rep(i,n){
        double x,y;
        cin >> x >> y;
        pos.emplace_back(x,y);
    }
    rep(i,m){
        double p,q;
        cin >> p >> q;
        pos.emplace_back(p,q);
    }
    const double INF = 1e18;
    const int tot = n+m+1;
    vector<vector<double> > dist(tot,vector<double>(tot,INF));
    rep(i,tot)rep(j,tot) dist[i][j] = calc_dist(pos[i],pos[j]);
    vector<double> speed(1<<tot,1);
    rep(i,1<<tot){
        rep(j,m){
            if(i>>(n+1+j)&1) speed[i] /= 2;
        }
    }
    vector<vector<double> > dp((1<<tot),vector<double>(tot,INF));
    dp[0][0] = 0;
    for(int bit=0;bit<(1<<tot);++bit){
        rep(v,tot){
            if(dp[bit][v] == INF) continue;
            rep(u,tot){
                if(~bit>>u&1){
                    chmin(dp[bit|1<<u][u],dp[bit][v]+dist[v][u]*speed[bit]);
                }
            }
        }
    }
    double ans = INF;
    int t = (1<<(n+1))-1;
    for(int bit = 0;bit<(1<<tot);bit++){
        if((bit&t) == t){
            chmin(ans,dp[bit][0]);
        } 
    }
    printf("%.10f\n",ans);
    return 0;
}