#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<int> > a(h,vector<int>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    vector<string> s(h);

    rep(i,h){
        rep(j,w){
            if(a[i][j] == 0) s[i].push_back('.');
            else{
                s[i].push_back(a[i][j] + '@') ;
            }
        }
    }
    rep(i,h){
        rep(j,w){
            cout << s[i][j];
        }
        cout << endl;
    }
}