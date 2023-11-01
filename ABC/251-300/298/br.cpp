#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<vector<int> > a(n,vector<int>(n)),b(n,vector<int>(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    rep(i,n)rep(j,n) cin >> b[i][j];
    auto rotate = [&](vector<vector<int> > &a) -> void{
        vector<vector<int> > rotated = a;
        rep(i,n)rep(j,n){
            rotated[i][j] = a[n-1-j][i];
        }
        a = rotated;
    };
    rep(cnt,4){
        rep(i,n){
            bool ok = true;
            rep(j,n){
                if(a[i][j] == 1 && b[i][j] == 0){
                    ok = false;
                    break;
                }
                if(i == n-1 && j == n-1){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
            if(!ok) break;
        }
        rotate(a);
    }
    cout << "No" << endl;
    return 0;
}