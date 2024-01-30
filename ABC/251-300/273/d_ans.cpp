#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int h,w,si,sj,n;
    cin >> h >> w >> si >> sj >> n;
    using MP = map<int,vector<int> >;
    MP mpL,mpR,mpU,mpD;
    rep(ni,n){
        int i,j;
        cin >> i >> j;
        mpR[i].push_back(j);
        mpL[i].push_back(-j);
        mpD[j].push_back(i);
        mpU[j].push_back(-i);
    }

    auto init = [&](MP &mp, int r){
        for(auto[n,p] : mp){
            sort(p.begin(),p.end());
            p.push_back(r);
        }
    };
    init(mpR,w+1);
    init(mpL,0);
    init(mpD,h+1);
    init(mpU,0);

    auto f = [&](MP &mp, int i, int j, int l, int r){
        auto it = mp.find(i);
        if(it == mp.end()) return min(j+l,r-1);
        auto& is = it->second;
        int wj = *lower_bound(is.begin(),is.end(),j);
        return min(j+l,wj-1);
    };

    int q;
    cin >> q;
    rep(qi,q){
        char d; int l;
        cin >> d >> l;
        if(d == 'R') sj = f(mpR,si,sj,l,w+1);
        if(d == 'L') sj = -f(mpL,si,-sj,l,0);
        if(d == 'D') sj = f(mpD,sj,si,l,h+1);
        if(d == 'U') sj = -f(mpU,sj,-si,l,0);
        printf("%d %d\n",si,sj);
    }
    return 0;
}