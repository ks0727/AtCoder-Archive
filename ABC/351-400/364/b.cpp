#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

int main(){
    int h,w;
    cin >> h >> w;
    int ci,cj;
    cin >> ci >> cj;
    ci--; cj--;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    string x;
    cin >> x;
    int n = x.size();
    rep(i,n){
        int ni = -1,nj=-1;
        if(x[i] == 'L'){
            ni = ci + di[3]; nj = cj + dj[3];
        }
        if(x[i] == 'R'){
            ni = ci + di[1]; nj = cj + dj[1];
        }
        if(x[i] == 'U'){
            ni = ci + di[2]; nj = cj + dj[2];
        }
        if(x[i] == 'D'){
            ni = ci + di[0]; nj = cj + dj[0];
        }
        if(ni<0||nj<0||ni >= h || nj >=w) continue;
        if(c[ni][nj] == '#') continue;
        ci = ni; cj = nj;
    }
    cout << ci+1 << ' ' << cj+1 << endl;
    return 0;
}