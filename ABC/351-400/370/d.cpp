#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<int,int>;
int di[] = {1,0,-1,0};
int dj[] = {0,-1,0,1};

int main(){
    int h,w,q;
    cin >> h >> w >> q;
    vector<vector<bool> > exploded(h,vector<bool>(w));
    int ans = h*w;
    while(q--){
        int i,j;
        cin >> i >> j;
        i--; j--;
        if(!exploded[i][j]){
            exploded[i][j] = true;
            ans--;
        }else{
            rep(d,4){
                int ni = i + di[d]; int nj = j+dj[d];
                while(1){
                    if(ni < 0 || nj < 0 || ni >= h || nj >= w) break;
                    if(!exploded[ni][nj]){
                        exploded[ni][nj] = true;
                        ans--;
                        break;
                    }
                    ni += di[d]; nj += dj[d];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}