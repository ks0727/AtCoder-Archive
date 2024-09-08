#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int h,w,q;
    cin >> h >> w >> q;
    vector<set<int> > rowSet(h),colSet(w);
    rep(i,h)rep(j,w){
        rowSet[i].insert(j);
        colSet[j].insert(i);
    }

    auto erase = [&](int i, int j){
        rowSet[i].erase(j);
        rowSet[j].erase(i);
    };

    rep(qi,q){
        int r,c;
        cin >> r >> c;
        r--; c--;
        {//行の処理
            auto it = rowSet[r].lower_bound(c);
            if(it != rowSet[r].end() && *it == c){ //まだそのマスが爆破されていない時
                erase(r,c);
                continue;
            }else{ //すでに爆発している時(一番近いマスを見る必要がある時)
                if(it != rowSet[r].end()) erase(r,*it);
                it = rowSet[r].lower_bound(c);
                if(it != rowSet[r].begin()) it--,erase(r,*it);
            }
        }
        {//列の処理
            auto it = colSet[c].lower_bound(r);
            if(it != colSet[c].end()) erase(*it,c);
            it = colSet[c].lower_bound(r);
            if(it != colSet[c].begin()) it--,erase(*it,c);
        }
    }
    int ans = 0;
    rep(i,h) ans += rowSet[i].size();
    cout << ans << endl;
    return 0;
}