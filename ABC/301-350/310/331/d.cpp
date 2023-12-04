#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    int n,q;
    cin >> n >> q;
    vector<string> p(n);
    rep(i,n) cin >> p[i];
    vector<int> row(n),colum(n);
    rep(i,n){
        rep(j,n){
            if(p[i][j] == 'B'){
                row[i]++;
                colum[j]++;
            }
        }
    }
    ll row_sum = 0;
    ll col_sum = 0;
    rep(i,n){
        row_sum += (ll)row[i];
        col_sum += (ll)colum[i];
    }
    auto seeknum = [&](int h,int w){
        ll sum = 0;
        int rrow = (h+1)/n; int rcol = (w+1)/n;
        int srow = (h+1)%n; int scol = (w+1)%n;
        sum = row_sum*(ll)rrow + col_sum*(ll)rcol;
        rep(i,srow) sum += (ll)row[i];
        rep(i,scol) sum += (ll)colum[i];
        sum -= row_sum;
        return sum;
    };
    rep(qi,q){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        ll sum = 0;
        sum = seeknum(c,d);
        int rrow = (a+1)/n; int rcol = (b+1)/n;
        int srow = (a+1)%n; int scol = (b+1)%n;
        rep(i,srow) sum -= ll(row[i]);
        rep(i,scol) sum -= ll(colum[i]);
        sum -= row_sum*(ll)rrow;
        sum -= col_sum*(ll)rcol;
        sum += seeknum(a,b);
        cout << sum << endl;
    }
    return 0;
}