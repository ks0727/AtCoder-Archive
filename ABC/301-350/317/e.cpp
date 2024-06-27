#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    const int INF = 1e9;
    vector<int> rows(h,INF),cols(w,INF);
    rep(i,h){
        rep(j,w){
            if(s[i][j] == 'v'){
                rows[i] = min(rows[i],j);
                cols[j] = min(cols[j],i);
            }else if(s[i][j] == '<'){
                
            }
        }
    }

}