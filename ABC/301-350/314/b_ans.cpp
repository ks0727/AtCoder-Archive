#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> c(n);
    vector<vector<int> > a(n);
    rep(i,n){
        cin >> c[i];
        a[i] = vector<int>(c[i]); //ベクトルの長さを後から定義できる！！
        rep(j,c[j]) cin >> a[i][j];
    }
    int x;
    cin >> x;

    vector<bool> p(n);
    rep(i,n){
        p[i] = false;
        rep(j,c[i]){
            if(a[i][j] == x) p[i] = true;
        }
    }
    int cmin = 100;
    rep(i,n){
        if(p[i]) cmin = min(cmin,c[i]);
    }
    vector<int> ans;
    rep(i,n){
        if(p[i] && c[i] == cmin) ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    for(int i: ans) cout << i << ' ';
    cout << endl;
    return 0;
}