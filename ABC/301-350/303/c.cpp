#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,m,h,k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    set<P> portions;
    rep(i,m){
        int px,py;
        cin >> px >> py;
        portions.insert({px,py});
    }
    int x = 0,y = 0;
    rep(i,n){
        if(s[i] == 'R') x+=1;
        if(s[i] == 'L') x-=1;
        if(s[i] == 'U') y+=1;
        if(s[i] == 'D') y-=1;
        h--;
        if(h < 0){
            cout << "No" << endl;
            return 0;
        }
        if(portions.count({x,y}) && h < k){
            portions.erase({x,y});
            h = k;
        }
    }
    cout << "Yes" << endl;
    return 0;
}