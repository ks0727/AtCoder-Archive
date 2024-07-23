#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<int,int>;
const int di[] = {0,1,0,-1};
const int dj[] = {1,0,-1,0};


int main(){
    int h,w,y;
    cin >> h >> w >> y;
    vector<vector<int> > a(h,vector<int>(w));
    vector<vector<P> > fs(y);
    rep(i,h)rep(j,w){
        cin >> a[i][j];
        a[i][j]--;
        if(a[i][j] < y) fs[a[i][j]].push_back(P(i+1,j+1));
    }
    vector<vector<bool> > sink(h+2,vector<bool>(w+2)),under(h+2,vector<bool>(w+2));
    rep(i,h+2)rep(j,w+2){
        if(i == 0 || j ==0 || i == h+1 || j == w+1){
            sink[i][j] = true;
            under[i][j] = true;
        } 
    }
    int ans = h*w;
    rep(yi,y){
        queue<P> q;
        for(auto [i,j] : fs[yi]){
            //cout << yi << ' ' << i << ' ' << j << endl;
            under[i][j] = true;
            rep(d,4){
                int ni = i+di[d]; int nj = j+dj[d];
                if(sink[ni][nj]){ 
                    //cout << ni << ' ' << nj << endl;
                    sink[i][j] = true;
                    ans--;
                    q.emplace(i,j);
                    break;
                }
            }
        }
        while (!q.empty())
        {
            auto [i,j] = q.front(); q.pop();
            rep(d,4){
                int ni = i+di[d]; int nj = j+dj[d];
                if(sink[ni][nj]) continue;
                if(under[ni][nj]){
                    sink[ni][nj] = true;
                    q.emplace(ni,nj);
                    ans--;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}