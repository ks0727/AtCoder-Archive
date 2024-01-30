#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int h,w,rs,cs;
    cin >> h >> w >> rs >> cs;
    int n;
    cin >> n;
    map<int,vector<int> > col,row;
    rep(i,n){
        int r, c;
        cin >> r >> c;
        col[c].push_back(r);
        row[r].push_back(c);
    }
    for(auto[num,arr] : col) sort(arr.begin(),arr.end());
    for(auto[num,arr] : row) sort(arr.begin(),arr.end());
    int q;
    cin >> q;
    P pos = P(rs,cs);
    auto f = [&](P pos, char d, int l){
        auto [x,y] = pos;
        if(d == 'U'){
            if(row.count(y)){
                int idx = lower_bound(row[y].begin(),row[y].end(),y) - row[y].begin();
                int ny = row[y][idx-1] + 1; 
                return P(x,ny);
            }else{
                return P(x,y-l);
            }
        }
        else if(d == 'D'){
            if(row.count(y)){
                int idx = lower_bound(row[y].begin(),row[y].end(),y) - row[y].begin();
                int ny = row[y][idx-1] - 1; 
                return P(x,ny);
            }else{
                return P(x,l+y);
            }
        }
        else if(d == 'L'){
            if(col.count(x)){
                int idx = lower_bound(col[x].begin(),col[x].end(),x) - col[x].begin();
                int nx = col[x][idx-1] + 1;
                return P(nx,y);
            }else{
                return P(x-l,y);
            }
        }
        else{
            if(col.count(x)){
                int idx = lower_bound(col[x].begin(),col[x].end(),x) - col[x].begin();
                int nx = col[x][idx-1] - 1;
                return P(nx,y);
            }else{
                return P(x+l,y);
            }
        }
    };
    rep(i,q){
        char d; int l;
        cin >> d >> l;
        pos = f(pos,d,l);
        cout << pos.second << ' ' << pos.first << endl;
    }
    return 0;
}