#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<double,double>;

int main(){
    int n;
    cin >> n;
    vector<P> pos;
    rep(i,n){
        double x,y;
        cin >> x >> y;
        pos.emplace_back(x,y);
    }
    auto f = [&](P p1,P p2)->double{
        auto [x1,y1] = p1;
        auto [x2,y2] = p2;
        return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    };
    rep(i,n){
        int out = 0;
        double now = 0;
        rep(j,n){
            if(i == j) continue;
            double dist = f(pos[i],pos[j]);
            if(now < dist){
                now = dist;
                out = j+1;
            }
        }
        cout << out << '\n';
    }
    return 0;
}