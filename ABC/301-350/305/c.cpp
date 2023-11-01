#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};
int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#') continue;
            int cnt = 0;
            rep(d,4){
                int ni = i; int nj = j;
                ni += di[d]; nj += dj[d];
                if(ni < 0 || nj < 0 || ni > h-1 || nj > w-1) continue;
                if(s[ni][nj] == '#') cnt++;
            }
            if(cnt > 1){
                cout << i+1 << ' ' << j+1 << endl;
                return 0;
            }
        }
    }
    return 0;
}