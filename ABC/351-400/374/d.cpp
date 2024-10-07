#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
struct Line{
    int a,b,c,d;
    Line(int a=0,int b=0,int c=0,int d=0):a(a),b(b),c(c),d(d){}
    void input(){
        cin >> a >> b >> c >> d;
    }
};

int main(){
    int n,s,t;
    cin >> n >> s >> t;
    vector<Line> ls(n);
    rep(i,n){
        ls[i].input();
    }
    vector<int> is;
    rep(i,n) is.push_back(i);
    int n2 = 1<<n;
    auto dist = [&](double x1, double y1, double x2,double y2,bool on){
        double res = 0;
        res = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        res = sqrt(res);
        if(on) return res/(double)t;
        else return res/(double)s;
    };
    double ans = 1e18;
    do{
        rep(i,n2){
            double si=0,sj=0;
            double now = 0;
            rep(j,n){
                if(i>>j&1){ //(A,B) -> (C,D)
                    now += dist(si,sj,ls[is[j]].a,ls[is[j]].b,false);
                    si = ls[is[j]].a;
                    sj = ls[is[j]].b;
                    now += dist(si,sj,ls[is[j]].c,ls[is[j]].d,true);
                    si = ls[is[j]].c;
                    sj = ls[is[j]].d;
                }else{
                    now += dist(si,sj,ls[is[j]].c,ls[is[j]].d,false);
                    si = ls[is[j]].c;
                    sj = ls[is[j]].d;
                    now += dist(si,sj,ls[is[j]].a,ls[is[j]].b,true);
                    si = ls[is[j]].a;
                    sj = ls[is[j]].b;
                }
            }
            ans = min(ans,now);
        }
    }while(next_permutation(is.begin(),is.end()));
    printf("%.10f\n",ans);
    return 0;
}