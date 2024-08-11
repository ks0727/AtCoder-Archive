#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

ll a[100][100][100];
ll s[101][101][101];

int main(){
    int n;
    cin >> n;
    rep(i,n)rep(j,n)rep(k,n) cin >> a[i][j][k];
    int q;
    cin >> q;
    rep(i,n){
        rep(j,n){
            rep(k,n){
                s[i+1][j+1][k+1] = s[i][j+1][k+1] + s[i+1][j][k+1] + s[i+1][j+1][k] 
                - s[i][j][k+1] - s[i][j+1][k] - s[i+1][j][k] 
                + s[i][j][k] + a[i][j][k];
            }
        }
    }
    rep(qi,q){
        int x1,x2,y1,y2,z1,z2;
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        x1--; y1--; z1--;
        ll result = s[x2][y2][z2] 
                    - s[x1][y2][z2] - s[x2][y1][z2] - s[x2][y2][z1]
                    + s[x1][y1][z2] + s[x1][y2][z1] + s[x2][y1][z1]
                    - s[x1][y1][z1];
        cout << result << endl;
    }
    return 0;
}