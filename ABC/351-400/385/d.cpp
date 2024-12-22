#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int n,m; ll si,sj;
    cin >> n >> m >> si >> sj;
    map<ll,set<ll> > row,col;
    rep(i,n){
        ll x,y;
        cin >> x >> y;
        row[y].insert(x);
        col[x].insert(y);
    }
    int ans = 0;
    ll cx = si; ll cy = sj;
    rep(mi,m){
        char d; ll c;
        cin >> d >> c;
        ll nx = cx; ll ny = cy;
        if(d == 'U'){
            ny += c;
            if(!col.count(cx)){ //もし今いるx座標に家がなかったら何もしない
                cx = nx; cy = ny;
                continue; 
            }else{
                auto it1 = col[cx].lower_bound(cy); //始まりの位置
                auto it2 = col[cx].upper_bound(ny); //終わりの位置
                if(it1 == col[cx].end() || it1 == it2 || *it1 > ny){ //この間にない
                    cx = nx; cy = ny;
                    continue;
                }
                it2--;
                while(it1 != it2 && *it1 <= ny){
                    row[*it1].erase(cx);
                    if(row[*it1].size() == 0) row[*it1].clear();
                    it1 = col[cx].erase(it1);
                    ans++;
                }
                if(it1 == it2 && it2 != col[cx].end() && *it1 <= ny){
                    row[*it1].erase(cx);
                    if(row[*it1].size() == 0) row[*it1].clear();
                    col[cx].erase(it1);
                    if(col[cx].size() == 0) col[cx].clear();
                    ans++;
                }
            }
        } 
        else if(d == 'D') {
            ny -= c;
            if(!col.count(cx)){ //もし今いるx座標に家がなかったら何もしない
                cx = nx; cy = ny;
                continue; 
            }else{
                auto it1 = col[cx].lower_bound(ny); //始まりの位置
                auto it2 = col[cx].upper_bound(cy); //終わりの位置
                if(it1 == col[cx].end() || it1 == it2 || *it1 > cy){ //この間にない
                    cx = nx; cy = ny;
                    continue;
                }
                it2--;
                while(it1 != it2 && *it1 <= cy){
                    row[*it1].erase(cx);
                    if(row[*it1].size() == 0) row[*it1].clear();
                    it1 = col[cx].erase(it1);
                    ans++;
                }
                if(it1 == it2 && it2 != col[cx].end() && *it1 <= cy){
                    row[*it1].erase(cx);
                    if(row[*it1].size() == 0) row[*it1].clear();
                    col[cx].erase(it1);
                    if(col[cx].size() == 0) col[cx].clear();
                    ans++;
                }
            }
        }
        else if(d == 'L'){
            nx -= c;
            if(!row.count(cy)){ //もし今いるy座標に家がなかったら何もしない
                cx = nx; cy = ny;
                continue; 
            }else{
                auto it1 = row[cy].lower_bound(nx); //始まりの位置
                auto it2 = row[cy].upper_bound(cx); //終わりの位置
                if(it1 == row[cy].end() || it1 == it2 || *it1 > cx){ //この間にない
                    cx = nx; cy = ny;
                    continue;
                }
                it2--;
                while(it1 != it2 && *it1 <= cx){
                    col[*it1].erase(cy);
                    if(col[*it1].size() == 0) col[*it1].clear();
                    it1 = row[cy].erase(it1);
                    ans++;
                }
                if(it1 == it2 && it2 != row[cy].end() && *it1 <= cx){
                    col[*it1].erase(cy);
                    if(col[*it1].size() == 0) col[*it1].clear();
                    row[cy].erase(it1);
                    if(row[cy].size() == 0) row[cy].clear();
                    ans++;
                }
            }
        }
        else if(d == 'R') {
            nx += c;
            if(!row.count(cy)){ //もし今いるy座標に家がなかったら何もしない
                cx = nx; cy = ny;
                continue; 
            }else{
                auto it1 = row[cy].lower_bound(cx); //始まりの位置
                auto it2 = row[cy].upper_bound(nx); //終わりの位置
                if(it1 == row[cy].end() || it1 == it2 || *it1 > nx){ //この間にない
                    cx = nx; cy = ny;
                    continue;
                }
                it2--;
                while(it1 != it2 && *it1 <= nx){
                    col[*it1].erase(cy);
                    if(col[*it1].size() == 0) col[*it1].clear();
                    it1 = row[cy].erase(it1);
                    ans++;
                }
                if(it1 == it2 && it2 != row[cy].end() && *it1 <= nx){
                    col[*it1].erase(cy);
                    if(col[*it1].size() == 0) col[*it1].clear();
                    row[cy].erase(it1);
                    if(row[cy].size() == 0) row[cy].clear();
                    ans++;
                }
            }
        }
        cx = nx; cy = ny;
    }
    cout << cx << ' ' << cy << ' ' << ans << endl;
    return 0;
}