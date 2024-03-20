#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int h,w,si,sj,n;
    cin >> h >> w >> si >> sj >> n;
    map<int,vector<int> > mpL,mpR,mpU,mpD;
    rep(ni,n){
        int i,j;
        cin >> i >> j;
        mpR[i].push_back(j);
        mpD[j].push_back(i);
        mpL[i].push_back(-j);
        mpU[j].push_back(-i);
    }
    auto init = [&](map<int,vector<int> > &mp, int r){
        for(auto &p : mp){
            sort(p.second.begin(),p.second.end());
            p.second.push_back(r); //番兵を挿入
        }
    };
    init(mpR,w+1);
    init(mpL,0);
    init(mpD,h+1);
    init(mpU,0);

    auto f = [&](map<int,vector<int> > mp, int i, int j, int l, int r){
        auto it = mp.find(i);
        if(it == mp.end()) return min(j+l,r);
        auto& is = it->second; //壁を含んでいる配列を参照で持っておく
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
        if(d == 'D') si = f(mpD,sj,si,l,h+1);
        if(d == 'U') si = -f(mpU,sj,-si,l,0);
        printf("%d %d\n",si,sj);
    }
    return 0;
}