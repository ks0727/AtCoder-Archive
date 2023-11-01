#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<int> > a(h,vector<int>(w)),b(h,vector<int>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    rep(i,h)rep(j,w) cin >> b[i][j];
    auto ver_shift = [&](vector<vector<int> > &a) ->void{
        vector<vector<int> > ver_shifted = a;
        rep(i,h){
            rep(j,w){
                if(i == h-1) ver_shifted[i][j] = a[0][j];
                else ver_shifted[i][j] = a[i+1][j];
            }
        }
        a = ver_shifted;
    };
    auto hori_shift = [&](vector<vector<int> > &a) ->void{
        vector<vector<int> > hori_shifted = a;
        rep(i,h){
            rep(j,w){
                if(j == w-1) hori_shifted[i][j] = a[i][0];
                else hori_shifted[i][j] = a[i][j+1];
            }
        }
        a = hori_shifted;
    };
    rep(s,h){
        rep(t,h){
            rep(i,h){
                rep(j,w){
                    if(a == b){
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
            hori_shift(a);
        }
        ver_shift(a);
    }
    cout << "No" << endl;
    return 0;
}