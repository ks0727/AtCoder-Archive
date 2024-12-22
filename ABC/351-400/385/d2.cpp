#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int n,m; ll sx,sy;
    cin >> n >> m >> sx >> sy;
    map<ll,set<ll> > col,row;
    rep(i,n){
        ll x,y;
        cin >> x >> y;
        col[x].insert(y);
        row[y].insert(x);
    }
    ll cx = sx; ll cy = sy;
    int ans = 0;

    rep(i,m){
        char d; ll c;
        cin >> d >> c;
        ll nx = cx; ll ny = cy;
        if(d=='U'){
            ny += c;
            auto it = col[cx].lower_bound(cy);
            while (it != col[cx].end() && *it <= ny){
                row[*it].erase(cx);
                it = col[cx].erase(it);
                ans++;
            }
        }
        else if(d == 'D'){
            ny -= c;
            auto it = col[cx].lower_bound(ny);
            while(it != col[cx].end() && *it <= cy){
                row[*it].erase(cx);
                it = col[cx].erase(it);
                ans++;
            }
        }
        else if(d == 'L'){
            nx -= c;
            auto it = row[cy].lower_bound(nx);
            while(it != row[cy].end() && *it <= cx){
                col[*it].erase(cy);
                it = row[cy].erase(it);
                ans++;
            }
        }
        else if(d == 'R'){
            nx += c;
            auto it = row[cy].lower_bound(cx);
            while(it != row[cy].end() && *it <= nx){
                col[*it].erase(cy);
                it = row[cy].erase(it);
                ans++;
            }
        }
        cx = nx; cy = ny;
    }
    cout << cx << ' ' << cy << ' ' << ans << endl;
    return 0;
}