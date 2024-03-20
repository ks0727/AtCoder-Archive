#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int h,w,is,js;
    cin >> h >> w >> is >> js;
    is--; js--;
    int n;
    cin >> n;
    vector<vector<int> > rs(h),cs(w);
    rep(i,n){
        int r,c;
        cin >> r >> c;
        r--; c--;
        rs[r].push_back(c);
        cs[c].push_back(r);
    }
    rep(i,h) if(rs[i].size() != 0) sort(rs[i].begin(),rs[i].end());
    rep(i,w) if(cs[i].size() != 0) sort(cs[i].begin(),cs[i].end());
    
    int q;
    cin >> q;
    int ni = is, nj = js;
    rep(qi,q){
        char d; int l;
        cin >> d >> l;
        auto f = [&](int ci, int cj,char d, int l){
            if(d == 'L'){
                if(rs[ci].size() == 0) return P(ci,max(0,cj-l)); //もしその行に壁がなかったらそのまま移動
                if(cj < rs[ci][0]) return P(ci,max(0,cj-l)); //もし現在の位置が左端の壁よりも左にあるならばそのまま移動できる
                int wall = *lower_bound(rs[ci].begin(),rs[ci].end(),cj-l)+1; //mnjは移動先より大きい最小の座標にある壁の位置
                int pos = max(0,cj-l);
                return P(ci,max(wall,cj-l));
            }
            if(d =='R'){
                if(rs[ci].size() == 0) return P(ci,min(cj+l,w-1)); //もしその行に壁がなかったらそのまま移動
                if(cj > rs[ci].back()) return P(ci,min(cj+l,w-1));
                int wall = *lower_bound(rs[ci].begin(),rs[ci].end(),cj)-1;
                int pos = min(cj+l,w-1);
                return P(ci,min(wall,cj+l));
            }
            if(d == 'U'){
                if(cs[cj].size() == 0) return P(max(0,ci-l),cj); //もしその行に壁がなかったらそのまま移動
                if(ci < cs[cj][0])return P(max(0,ci-l),cj);
                int wall = *lower_bound(cs[cj].begin(),cs[cj].end(),ci-l)+1;
                int pos = max(ci-l,0);
                return P(max(wall,pos),cj);
            }
            else{
                if(cs[cj].size() == 0) return P(min(ci+l,h-1),cj); //もしその行に壁がなかったらそのまま移動
                if(ci > cs[cj].back()) return P(min(ci+l,h-1),cj); //もしも現在の位置が最大の壁よりも大きいならそのまま移動できる
                int wall = *lower_bound(cs[cj].begin(),cs[cj].end(),ci) - 1;
                int pos = min(ci+l,h-1);
                return P(min(wall,pos),cj);
            }
        };
        P now = f(ni,nj,d,l);
        cout << now.first + 1 << ' ' << now.second + 1 << endl;
        ni = now.first; nj = now.second;
    }
    return 0;
}