#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int h,w,rs,cs;
    cin >> h >> w >> rs >> cs;
    int n;
    cin >> n;
    map<int,vector<int> > row,col;
    rep(i,n){
        int r,c;
        cin >> r >> c;
        row[r].push_back(c);
        col[c].push_back(r);
    }
    for(auto &[x,arr] : row){
        arr.push_back(0);
        arr.push_back(w+1);
    } 
    for(auto &[x,arr] : col){
        arr.push_back(0);
        arr.push_back(h+1);
    } 
    for(auto &[x,arr] : row) sort(arr.begin(),arr.end());
    for(auto &[x,arr] : col) sort(arr.begin(),arr.end());
    int q;
    cin >> q;
    auto f = [&](P now,char d, int l){
        auto [ch,cw] = now;
        if(d == 'L'){
            if(row[ch].size() == 0){ //その行に壁がなかったら
                return P(ch,max(cw-l,1));
            }
            int wi = lower_bound(row[ch].begin(),row[ch].end(),cw)-row[ch].begin();
            int wall = row[ch][wi-1];
            int nw = max(1,cw-l);
            return P(ch,max(wall+1,nw));
        }else if(d == 'R'){
            if(row[ch].size() == 0){ //その行に壁がなかったら
                return P(ch,min(cw+l,w));
            }
            int wall = *lower_bound(row[ch].begin(),row[ch].end(),cw);
            int nw = min(w,cw+l);
            return P(ch,min(wall-1,nw));
        }else if(d == 'U'){
            if(col[cw].size() == 0){ //その列に壁がなかったら
                return P(max(1,ch-l),cw);
            }
            int wi = lower_bound(col[cw].begin(),col[cw].end(),ch)-col[cw].begin();
            int wall = col[cw][wi-1];
            int nh = max(1,ch-l);
            return P(max(nh,wall+1),cw);
        }else{
            if(col[cw].size() == 0){ //その列に壁がなかったら
                return P(min(h,ch+l),cw);
            }
            int wall = *lower_bound(col[cw].begin(),col[cw].end(),ch);
            int nh = min(h,ch+l);
            return P(min(nh,wall-1),cw);
        }
    };
    int ch = rs, cw = cs;
    P now = P(ch,cw);
    rep(qi,q){
        char d; int l;
        cin >> d >> l;
        now = f(now,d,l);
        cout << now.first << ' ' << now.second << endl;
    }
    return 0;
}