#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
const int di[] = {1,-1,-1,1};
const int dj[] = {1,1,-1,-1};

int main(){
    int h,w;
    cin >> h >> w;
    int n = min(h,w);
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    vector<P> middles;
    rep(i,h){
        rep(j,w){
            if(c[i][j] == '#'){
                rep(v,4){
                    int ni = i; int nj = j;
                    ni += di[v]; nj += dj[v];
                    if(ni > h-1 || ni < 0 || nj < 0 || nj > w-1) break;
                    if(c[ni][nj] != '#') break;
                    if(v == 3){
                        middles.push_back({i,j});
                    }
                }
            }
        }
    }
    vector<int> ans(n);
    for(auto middle : middles){
        int i = middle.first; int j = middle.second;
        int size = 0;
        while(c[i][j] == '#' && i < h && j < w){
            i++; j++;
            size++;
            if(i > h-1 || j > w-1) break;
        }
        if(size >= 2) ans[size-2]++;
    }
    
    rep(i,n) cout << ans[i] << ' ';
    return 0;
}