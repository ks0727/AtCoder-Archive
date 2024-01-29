#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    vector<int> x(w);
    rep(i,w){
        int xi = 0;
        rep(j,h){
            if(c[j][i] == '#')  xi++;
        }
        x[i] = xi;
    }
    rep(i,w){
        cout << x[i] << ' ';
    }
    cout << endl;
    return 0;
}