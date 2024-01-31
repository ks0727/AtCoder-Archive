#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int h,w,si,sj;
    cin >> h >> w >> si >> sj;
    int n;
    cin >> n;
    map<int,vector<int> > col,row;
    rep(i,n){
        int r, c;
        cin >> r >> c;
        col[c].push_back(r);
        row[r].push_back(c);
    }
    for(auto &mp : col) sort(mp.second.begin(),mp.second.end());
    for(auto &mp : row) sort(mp.second.begin(),mp.second.end());
    int q;
    cin >> q;
    P pos = P(si,sj);
    auto f = [&](P pos, char d, int l){
        auto [i,j] = pos;
        if(d == 'U'){
            if(col.count(j)){
                int wall = *lower_bound(col[j].begin(),col[j].end(),i);
                if(i < wall){
                    return P(max(1,i-l),j);
                }else{
                    int ni = max(i-l,wall+1);
                    return P(max(ni,1),j);
                }
            }else{
                return P(max(1,i-l),j);
            }
        }
        else if(d == 'D'){
            if(col.count(j)){
                int wall = *lower_bound(col[j].begin(),col[j].end(),i);
                if(i > wall){
                    return P(min(h,i+l),j);
                }else{
                    int ni = max(i+l,wall-1);
                    return P(min(ni,h),j);
                }
            }else{
                return P(min(h,i+l),j);
            }
        }
        else if(d == 'L'){
            if(row.count(i)){
                int wall = *lower_bound(row[i].begin(),row[i].end(),j);
                if(wall > j) return P(i,max(1,j-l));
                else{
                    int nj = max(j-l,wall+1);
                    return P(i,max(1,nj));
                }
            }else{
                return P(i,max(1,j-l));
            }
        }
        else{
            if(row.count(i)){
                int wall = *lower_bound(row[i].begin(),row[i].end(),j);
                if(wall < j) return P(i,min(j+l,w));
                else{
                    int nj = min(j+l,wall-1);
                    return P(i,min(nj,w));
                }
            }else{
                return P(i,min(j+l,w));
            }
        }
    };
    rep(i,q){
        char d; int l;
        cin >> d >> l;
        pos = f(pos,d,l);
        cout << pos.first << ' ' << pos.second << endl;
    }
    return 0;
}